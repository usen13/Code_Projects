/******************************************
Implementing a generic object pool that:

Pre-allocates a fixed number of objects at construction
acquire() — returns an available object, blocks if none available
release(obj) — returns object back to the pool
Is thread safe
Uses RAII so objects are automatically returned to the pool when they go out of scope
****************************************/
#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <stack>
#include <mutex>
#include <condition_variable> 

template <typename T>
class ObjectPool {
public:

    using PoolData = std::unique_ptr<T, std::function<void(T*)>>;

    ObjectPool (int count, std::function<std::unique_ptr<T>()> resource) {
        while (count > 0) {
            m_ObjectPool.push(resource());
            --count;
        }
    }

    PoolData acquire () {
        std::unique_lock<std::mutex> lock(m_mutex);
        // Wait till the stack is not empty anymore.
        m_cv.wait(lock, [&] () {
            return !m_ObjectPool.empty();
        });

        auto obj = std::move(m_ObjectPool.top());
        T* temp = obj.release();
        m_ObjectPool.pop();

        // The deleter below release the object back into the pool, incase of deletiong or going out of scope
        return PoolData(temp, [this] (T* obj) {
            release(std::unique_ptr<T>(obj));
        });
    }

    void release (std::unique_ptr<T> obj) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_ObjectPool.push(std::move(obj));
        m_cv.notify_one();
    }

    
private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::stack<std::unique_ptr<T>> m_ObjectPool;
};

int main() {
    ObjectPool<std::string> pool(3, []() { 
        return std::make_unique<std::string>("resource"); 
    });

    auto obj1 = pool.acquire();
    auto obj2 = pool.acquire();
    auto obj3 = pool.acquire();
    // pool is now empty
    std::cout << "Pool empty, all 3 acquired" << std::endl;

    // obj1 goes out of scope here — automatically returned to pool
    {
        auto temp = pool.acquire(); // blocks until one is available
    }

    // Automatically returned to pool when temp goes out of scope
    //pool.release(std::move(obj2));
    //pool.release(std::move(obj3));
}