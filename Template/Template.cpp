#include <memory>
#include "STL.h"
#include "LinkedList.h"

class MyCallback {
    public:
    void operator() (int a) {
        std::cout << "The operation being perfomred is on:" << a << std::endl;
    }
};

template <typename Callback> void performAction(int a, Callback callback) {
    std::cout << "The action is to be done on:" << a << std::endl;
    callback(a);
}

int main() {
    MyCallback callback;
    performAction(23, callback);
    auto tempObj = std::make_unique<TemplateClass>();
    
    int a = 25;
    int* b = &a;
    std::cout << "Value of a is: " << *b << std::endl;
    tempObj->setValue(*b, a);

    std::cout << "Value stored in the class is:" << tempObj->getValue() << std::endl;
    std::cout << "The largest value currently stored is:" << tempObj->LargestNum(a,*b) << std::endl;
    
    std::vector<int> rand (5, 5);
    auto funcPtr = [rand] (int x) {

        for (const auto& val : rand) {
            std::cout << "Value in vector: " << val + x << std::endl;
        }
    };
    funcPtr(3);
    // std::unordered_map<int, std::string> sampleMap;
    // sampleMap[1] = "One";
    // sampleMap[2] = "Two";
    // sampleMap[3] = "Three";
    // sampleMap[1] = "Four";

    // std::cout << "Number of elements in the unordered map: " << sampleMap.size() << std::endl;
    // std::cout << "Four appears this number of times: " << sampleMap.count(1) << std::endl;
    // std::cout << sampleMap[3] << std::endl;
    // for (const auto& pair : sampleMap) {
    //     std::cout << "Key: " << pair.first << " Value: " << pair.second << std::endl;
    // }

    class Solution sol;
    int num = -121;
    if (sol.isPalindrome(num)) {
        std::cout << num << " is a palindrome number." << std::endl;
    } else {
        std::cout << num << " is not a palindrome number." << std::endl;
    }

    class Sol{
        public:
        Sol () { std::cout << "Sol Constructor Called" << std::endl; }
        ~Sol () { std::cout << "Sol Destructor Called" << std::endl; }
    };
    {
        auto tempClass = std::make_unique<Sol>();
        std::cout << "Size of tempClass is: " << sizeof(*tempClass) << std::endl;
        std::cout << "Address of tempClass is: " << tempClass.get() << std::endl;
    }

    // MoveConstructorExample moveObj = new MoveConstructorExample(10);
    // std::cout << "Data size in moveObj: " << moveObj->GetSize() << std::endl;
    // std::cout << "Pointer data in moveObj: " << moveObj->GetPointerData() << std::endl;
    // MoveConstructorExample moveObj2 = std::move(moveObj);
    // std::cout << "After move, Data size in moveObj2: " << moveObj2->GetSize() << std::endl;
    // std::cout << "After move, Pointer data in moveObj2: " << moveObj2->GetPointerData() << std::endl;

    StringClass<std::string>* stringObj = new StringClass<std::string>("Hello, World!");
    std::cout << "StringClass with string: " << stringObj->getString() << std::endl;
    delete stringObj;
    
    StringClass<int> intString(12345);
    StringClass<std::string> strString("Hello, Templates!");
    std::cout << "StringClass with int: " << intString.getString() << std::endl;

    std::cout << "StringCLass witn int size is: " << sizeof(intString) << std::endl;
    std::cout << "StringClass with string size is: " << sizeof(strString) << std::endl;

    
    std::cout << "Division of 5.4 and 3 is: " << divide<double>(5, 3) << std::endl;

    Singleton& singletonInstance = Singleton::getInstance();
    Singleton& extraSingletonInstance = Singleton::getInstance();

    singletonInstance.showMessage();
    extraSingletonInstance.showMessage();

    std::cout << "Value of a in Singleton: " << singletonInstance.getA() << std::endl << extraSingletonInstance.getA() << std::endl;
    singletonInstance.setA(42);
    std::cout << "Value of a in Singleton after modification: " << singletonInstance.getA() << std::endl << extraSingletonInstance.getA() << std::endl;

    return 0;
}