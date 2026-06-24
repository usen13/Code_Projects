#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

class Player {
    std::string name_;
    int score_ = 0;

public:
    Player(std::string name, int score) : name_(std::move(name)), score_(score) {}

    // TODO:
    // - const std::string& name() const;
    // - std::string& name();            (optional, decide if you want mutability)
    // - int score() const;
    // - void setScore(int);
    const std::string& getName() const {
        return name_;
    };

    std::string& getMutableName() {
        return name_;
    }

    int score() const {
        return score_;
    }
    void setScore(const int& score) {
        score_ = score;
    }
};

// int main() {
//     const Player p("A", 5);
//     std::cout << p.getName();
// }

/*
Task2 operator overloading with const and non-const overloads
*/

//#include <string>

class Text {
    std::string s_;

public:
    explicit Text(std::string s) : s_(std::move(s)) {}

    // TODO:
    // char& operator[](size_t i);
    // const char& operator[](size_t i) const;
    char& operator[](std::size_t i) {
        if (i >= s_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return s_[i];
    };

    const char& operator[](std::size_t i) const {
        if (i >= s_.size()) {
            throw std::out_of_range("Index out of range");
        }
        return s_[i];
    }

    const std::string& str() const { return s_; }
};

// int main () {
//     Text t("abc");
//     t[0] = 'z';                 // ok

//     const Text ct("abc");
//     char c = ct[0];
//     //ct[0] = 'z';               // error: cannot modify through const object

//     std::cout << t.str() << " " << ct.str() << std::endl;
//     return 0;
//  }

/*
Task3 Const-correct “view” API and chaining
    Provide append(char) only for non-const objects.
    Provide size() and front() for both.
    Ensure front() returns char& for non-const, and const char& for const.
*/

class CharBuffer {
    std::vector<char> buf_;

public:
    CharBuffer() = default;

    void append(char c) { buf_.push_back(c); }

    // TODO:
    // size_t size() const;
    // char& front();
    // const char& front() const;
    size_t size() const {
        return buf_.size();
    }

    char& front() {
        if (buf_.empty()) throw std::out_of_range("Buffer is empty");
        return buf_[0];
    }

    const char& front() const {
        if (buf_.empty()) throw std::out_of_range("Buffer is empty");
        return buf_[0];
    }

};

/*
Problem 4 (Hard): mutable and “logical constness” (cache)
    checksum() must be callable on const objects.
    It must cache the computed checksum so repeated calls are cheap.
    Updating the data must invalidate the cache.
    Use mutable responsibly.
*/

class Document {
    std::string text_;
    mutable bool cacheValid_ = false;
    mutable uint32_t cached_ = 0;

    static uint32_t compute(const std::string& s) {
        // Simple toy hash (not cryptographic)
        uint32_t h = 2166136261u;
        for (unsigned char c : s) {
            h ^= c;
            h *= 16777619u;
        }
        return h;
    }

public:
    explicit Document(std::string t) : text_(std::move(t)) {}

    // Mutator must invalidate cache
    void setText(std::string t) {
        text_ = std::move(t);
        // TODO invalidate
        cacheValid_ = false;
        cached_ = 0;
    }

    const std::string& text() const { return text_; }

    // TODO: uint32_t checksum() const;
    uint32_t checksum() const {
        if (!cacheValid_) {
            cached_ = compute(text_);
            cacheValid_ = true;
        }
        return cached_;
    }
};


/*
Problem 5 (Easy): When to return by const ref vs by value
    Implement the Stats class with the specified member functions.
    Explain in a comment why label() must return by value.
*/

class Stats {
    std::string name_;
    int count_ = 0;

public:
    Stats(std::string name, int count) : name_(std::move(name)), count_(count) {}

    // Implement:
    // const std::string& name() const;
    // int count() const;              // by value
    // void setCount(int);
    
    const std::string& GetName() const {
        return name_;
    };

    int GetCount() const {
        return count_;
    }

    void setCount(int value) {
        count_ = value;
    }
    // Now add a function:
    // std::string label() const;      // returns "name:count"
    // (This MUST return by value; explain why.)
    std::string label() const {
        return name_ + ":" + std::to_string(count_);
    }; 
};

// Problem 6 (Medium): Dangling reference from const ref to temporary
// Solution using value
// std::string make_message(bool excited) {
//     std::string s = "hello";
//     if (excited) s += "!!!";
//     return s; // BUG
// }

// int main() {
//     std::string r = make_message(true);
// }

// Solution by static variable

const std::string& make_message(bool excited) {
    static std::string s; 
    s = "hello";
    if (excited) s += "!!!";
    return s; // BUG
}

// int main() {
//     std::string r = make_message(true);
// }

// The problem with using a static variable is that it is alive for the entire duration of the program, and when
// calling make_message with different bool values will change the same variable in the same memory location.

/*
 * Problem 6 (medium): Reference invalidation in containers
    * Fixes
    * Provide two:
    * Avoid holding references across operations that may reallocate
    * Ensure capacity is sufficient beforehand (reserve), and explain the limitations
*/

//#include <vector>

// int main() {
//     std::vector<int> v = {1,2,3};
//     int& r = v[0];
//     v.push_back(4);   // maybe realloc
//     r = 99;           // ??
// }

// int main() {
//     std::vector<int> v = {1,2,3};
//     int r = v[0];
//     v.push_back(4);   // maybe realloc
//     r = 99;           // ??
// }

// Ensuring capacity

// int main() {
//     std::vector<int> v(4, (1,2,3));
//     v.reserve(4); 
//     int r = v[0];
//     v.push_back(4);   // maybe realloc
//     r = 99;           // ??
// }


/*
    * Problem 7 (medium): Temporary lifetime and reference binding
    * Key concepts
    * Lifetime extension for const T&
    * Non-const lvalue refs cannot bind to temporaries
    * Pointer from c_str() of a temporary dangles immediately
*/
// #include <string>

// std::string make();

// int main() {
//     const std::string& a = make();       // Since make() returns by value, a will point to a dangling reference
//     std::string& b = make();             // Will throw an error because the make should return an lvalue which it is not doing
//     const char* p = make().c_str();      // Same as the first case, p will point to a dangling reference, since the memory allocated in make() is freed
// }
// The fix would be store the value returned by make() in a variable with sufficient lifetime, e.g., a local variable in main().


/*
Problem 8 (medium): Const-correctness and thread safety
    * Task
    * Provide two correct designs:
    * Token remains a view but cannot be constructed from temporaries (show how you’d enforce/document this)
    * Token owns the storage (e.g., std::string)
*/

#include <string_view>
//#include <string>

class Token {
    std::string_view view_;

public:
    explicit Token(std::string_view v) : view_(v) {}
    std::string_view view() const { return view_; }
};

Token make_token() {
    std::string s = "abc";
    return Token{s};   // BUG: view_ will dangle
}

// The issue: since std::string_view does not own the memory it points to, if a temporary string is passed to Token, 
// the view_ member will point to invalid memory once the temporary is destroyed.

// Solution is to make view_ a std::string to own the memory
// Another solution is to enfore that Token remains a std::string_view but cannot be constructed by temporaries

class SafeToken {
    std::string str_;
public:

    explicit SafeToken(const std::string& s) : str_(s) {}
    std::string_view view() const { return str_; }
};
