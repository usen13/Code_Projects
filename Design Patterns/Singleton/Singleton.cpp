#include <iostream>

// class Singleton {

//     private:
//         Singleton() {
//             std::cout << "Singleton instance created." << std::endl;
//         }
//         static Singleton* instance;
//     public:
//         static getSingletonInstance () {
//             Singleton instance;
//         }
// };

class String {

    private: 
    char* m_buffer;
    size_t m_size;

    public:
    String (const char* string)
    {
        m_size = sizeof(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
    }

    ~String() {
        delete[] m_buffer;
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_buffer;
    return stream;
}

void GetNumber(int&& i) {
    std::cout << "lvalue:" << i << std::endl; 
}

void GetNumber(const int& i) {
    std::cout << "lvalue:" << i << std::endl; 
}

int main () {
    String stringc = "Utsav";
    String stringb = stringc;
    std::cout << stringc << std::endl;
    std::cout << stringb << std::endl;

    int i = 10;
    GetNumber(10);
    GetNumber(i);
    return 0;
}