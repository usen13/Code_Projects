#pragma once
#include <string>
#include <iostream>

class Subscriber {
public:
    Subscriber (const std::string& name) {
        someText = "PlaceHolder";
        subName = name;
    };

    std::string getName () const {
        return subName;
    }

    void update (const std::string& text) {
        std::cout << "Subscriber " << subName << " has been updated with text: " << text << std::endl; 
        someText = text;
    }

private:
    std::string someText;
    std::string subName;
};