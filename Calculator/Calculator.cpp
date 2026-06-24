#include "./Headers/Calculator.h"

using namespace std;


int main()
{
    Calculator calc;
    //cin.get();
    cout << "Hello, What would you like to calculate today" << endl;
    cout << "1) Add" << endl;
    cout << "2) Subtract" << endl;
    cout << "3) Multiply" << endl;
    cout << "4) Divide" << endl;
    cout << "5) Exit" << endl;
    int choice, a, b;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 5) {
        cout << "Goodbye!" << endl;
        return 0;
    }
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    switch (choice)
    {
    case 1:
        cout << "The sum of " << a << " and " << b << " is " << calc.add(a, b) << endl;
        break;
    case 2:
        cout << "The difference of " << a << " and " << b << " is " << calc.subtract(a, b) << endl;
        break;
    case 3:
        cout << "The product of " << a << " and " << b << " is " << calc.multiply(a, b) << endl;
        break;
    case 4:
        cout << "The quotient of " << a << " and " << b << " is " << calc.divide(a, b) << endl;
        break;    
    default:
        break;
    }
    return 0;
    
}