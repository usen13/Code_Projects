#include <iostream>
class Singleton {    // Your implementation here
private:
    Singleton () = default;
    std::string text = "Hello World";

public:
    static Singleton& getInstance() {
        static Singleton* instance = new Singleton;
        return *instance;
    }

    std::string getText () const {
        return text;
    }
    Singleton (Singleton& obj) = delete;
    Singleton operator=(Singleton& obj) = delete;
};

int main() {
    Singleton& a = Singleton::getInstance();
    Singleton& b = Singleton::getInstance();
    std::cout << a.getText() << std::endl;
    std::cout << b.getText() << std::endl;

    // a and b should refer to the same instance
    std::cout << (&a == &b ? "Same instance" : "Different instances") << std::endl;
}