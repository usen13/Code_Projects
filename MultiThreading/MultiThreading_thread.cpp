#include  "Multithreading_header.h"
#include <future>

int main () {


    {
        bool (*primeChecker)(const int& num);
        void (*Printer)(const uint64_t& num);
        Printer = PrintResult;
        primeChecker = CalculatePrimes;

        bool isPrime = primeChecker(233);
        auto lambda = [] () { std::cout <<"This is a lambda function" << std::endl;};
        lambda(); // Call the lambda function
        std::cout << "233 is a prime:" << isPrime << std::endl;
        std::cout << "Multi Threading example" << std::endl;
        Timer timer;
        std::thread prime (PrintResult, 17446744073709551615ULL );
        std::thread prime2 (PrintResult, 17346744073709551613ULL );
        
        prime.join();
        prime2.join();
    }

    {
        std::cout << "Single threading example" << std::endl;
        Timer timer;
        PrintResult(17446744073709551615ULL);
        PrintResult(17346744073709551613ULL);
        
    }

    return 0;
}