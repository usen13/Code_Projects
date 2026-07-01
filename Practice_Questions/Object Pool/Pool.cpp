/******************************************
Implementing a generic object pool that:

Pre-allocates a fixed number of objects at construction
acquire() — returns an available object, blocks if none available
release(obj) — returns object back to the pool
Is thread safe
Uses RAII so objects are automatically returned to the pool when they go out of scope
****************************************/
#include <string>
#include <functional>
#include <memory>
#include <stack>
#include <mutex>
#include <condition_variable> 

template <typename T>
class ObjectPool {
public:
    ObjectPool (int count, std::function<std::unique_ptr<T>()> resource) {
        while (count > 0) {
            m_ObjetPool.push(resource());
            --count;
        }
    }

    std::unique_ptr<T> acquire () {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_ObjetPool.empty()) {
            m_cv.wait(lock, [&] () {
                return !m_ObjetPool.empty();
            });
        }
        std::unique_ptr<T> temp = std::move(m_ObjetPool.top());
        m_ObjetPool.pop();
        return temp;
    }

    void release (std::unique_ptr<T>&& obj) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_ObjetPool.push(std::move(obj));
        m_cv.notify_one();
    }

    
private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::stack<std::unique_ptr<T>> m_ObjetPool;
};

int main() {
    ObjectPool<std::string> pool(3, []() { 
        return std::make_unique<std::string>("resource"); 
    });

    auto obj1 = pool.acquire();
    auto obj2 = pool.acquire();
    auto obj3 = pool.acquire();
    // pool is now empty

    // obj1 goes out of scope here — automatically returned to pool
    {
        auto temp = pool.acquire(); // blocks until one is available
    }

    pool.release(std::move(obj2));
    pool.release(std::move(obj3));
}