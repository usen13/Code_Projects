#include <thread>
#include <cmath>
#include <chrono>
#include <iostream>
#include <mutex>

bool CalculatePrimes (const int& num) {
    if (num % 2 == 0) return false;
    if (num < 2) return false;
    if (num == 2) return true;

    for (int i = 3; i < sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
static std::mutex m_mutexValue;
void PrintResult(const uint64_t& num) {

    bool result = CalculatePrimes(num);
    std::cout << "Number " << num << " is " << (result ? "prime" : "not a prime") << std::endl;
}

class Timer {

    public:
    Timer () {
        startTime = std::chrono::high_resolution_clock::now();
    }

    ~Timer () {
        auto endtime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endtime - startTime;
        std::cout << "Duration :" << duration.count() << " seconds" << std::endl;
    }

    private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};