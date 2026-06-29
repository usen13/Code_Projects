/*****************************************************************
Implementing a thread-safe message queue using C++ concurrency primitives. It supports:

push(val) — add a message to the queue
pop() — block until a message is available, then return it
tryPop() — return immediately with std::optional<T>, empty if queue is empty
Be safe to use from multiple producer and consumer threads simultaneously
*****************************************************************/
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <optional>
#include <condition_variable>

template <typename T>
class MessageQueue {
public:
    MessageQueue () = default;
    void push (const T& x) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(x);
        m_cv.notify_one();
    }

    void push (T&& x) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(std::move(x));
        m_cv.notify_one();
    }

    T pop () {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [this]() { return !m_queue.empty(); });
        
        T temp = m_queue.front();
        m_queue.pop();
        return temp;
    }

    std::optional<T> tryPop () {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_queue.empty()) {
            return std::nullopt;
        } else {
            T temp = m_queue.front();
            m_queue.pop();
            return temp;
        }
    }

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cv;
};

int main() {
    MessageQueue<int> q;

    std::thread producer([&]() {
        for (int i = 0; i < 5; i++) {
            q.push(i);
        }
    });

    std::thread consumer([&]() {
        for (int i = 0; i < 5; i++) {
            std::cout << q.pop() << std::endl;
        }
    });

    producer.join();
    consumer.join();
}