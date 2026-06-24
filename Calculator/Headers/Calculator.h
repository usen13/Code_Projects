#include <iostream>
class Calculator
{
public:
    Calculator();
    ~Calculator();

    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    float divide(int a, int b);
}; 

Calculator::Calculator()
{
    std::cout << "Calculator constructor called." << std::endl;
}

Calculator::~Calculator()
{
    std::cout << "Calculator destructor called." << std::endl;
}

int Calculator::add(int a, int b)
{
    return a + b;
}

int Calculator::subtract(int a, int b)
{
    return a - b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}

float Calculator::divide(int a, int b)
{
    return a / b;
}