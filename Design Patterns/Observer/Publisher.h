#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Subscriber.h"

class Publisher {
public:
    Publisher (std::unique_ptr<Subscriber> subObj) {
        subscriber_list.push_back(std::move(subObj));
    } 

    void add_subscriber (std::unique_ptr<Subscriber> subscriber) {
        auto it = std::find_if(subscriber_list.begin(), subscriber_list.end() , 
                            [&subscriber](const std::unique_ptr<Subscriber>& current) {
            return current.get()->getName() == subscriber.get()->getName();
        });

        if (it != subscriber_list.end()) {
            std::cout << "Subscriber already exists in the list" << std::endl;
        } else {
            subscriber_list.push_back(std::move(subscriber));
        }
    }

    void remove_subscriber(const std::string& subscriberName) {
            subscriber_list.erase(
                std::remove_if(
                    subscriber_list.begin(),
                    subscriber_list.end(),
                    [subscriberName](const std::unique_ptr<Subscriber>& current) {
                        return current.get()->getName() == subscriberName;
                    }),
                subscriber_list.end());
        std::cout << "A subsriber has been removed from the list" << std::endl; 
    }

    void remove_all_subscriber() {
        subscriber_list.clear();
    }

    void send_udpate(const std::string& text) {
        std::cout << "Sending update to all the subscribers" << std::endl;
        for (const auto& subscriber : subscriber_list) {
            subscriber->update(text);
        }
    }
private:
    std::vector<std::unique_ptr<Subscriber>> subscriber_list;
};