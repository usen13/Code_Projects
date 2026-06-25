#include <iostream>
class Singleton {
private:
    Singleton () = default;
    std::string text = "Hello World";

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    std::string getText () const {
        return text;
    }
    Singleton (Singleton& obj) = delete;
    Singleton& operator=(Singleton& obj) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

int main() {
    Singleton& a = Singleton::getInstance();
    Singleton& b = Singleton::getInstance();
    std::cout << a.getText() << std::endl;
    std::cout << b.getText() << std::endl;

    std::cout << (&a == &b ? "Same instance" : "Different instances") << std::endl;
}