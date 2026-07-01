/*****************************************
Implements a token bucket rate limiter. It does the following:

Initialized with a max capacity and a refill rate (tokens per second)
Tokens refill automatically over time up to max capacity
Is thread safe
Interface:
allowRequest(int tokens) — returns true if enough tokens are available and consumes them, false otherwise
*****************************************/
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>

class RateLimiter {
public:
    RateLimiter (int capacity, int refill) : 
    m_capacity(capacity), 
    m_refillRate(refill),
    m_tokens(capacity),
    m_lastRefillTime(std::chrono::steady_clock::now()) {}

    bool allowRequest (int tokens) {
        std::lock_guard<std::mutex> lock(m_mutex);
        refillRate();
        if (tokens > m_tokens) {
            std::cout << "Request exceeded token count" << std::endl;
            return false;
        }
        m_tokens -= tokens;
        return true;
    }

private:
    void refillRate() {
        int elapsedTime = std::chrono::duration_cast<std::chrono::seconds> (std::chrono::steady_clock::now() - m_lastRefillTime).count();
        if (elapsedTime <= 0) {
            return;
        }
        int refillTokens = m_refillRate * elapsedTime;
        m_tokens = std::min(m_capacity, m_tokens + refillTokens);
        m_lastRefillTime = std::chrono::steady_clock::now();
    }

    int m_capacity;
    int m_refillRate;
    int m_tokens;
    std::mutex m_mutex;
    std::chrono::steady_clock::time_point m_lastRefillTime;

};

int main() {
    RateLimiter limiter(10, 5); // capacity=10, refill=5 tokens/sec

    std::cout << limiter.allowRequest(3) << std::endl;  // true  (7 remaining)
    std::cout << limiter.allowRequest(5) << std::endl;  // true  (2 remaining)
    std::cout << limiter.allowRequest(3) << std::endl;  // false (only 2 available)
    
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    std::cout << limiter.allowRequest(5) << std::endl;  // true  (refilled)
}