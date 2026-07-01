/******************************************
Implementing a publish/subscribe event system:

subscribe(eventName, callback) — register a callback for an event, returns a subscription ID
unsubscribe(id) — remove a callback by ID
publish(eventName, data) — call all callbacks registered for that event
Support multiple subscribers per event
Be thread safe
******************************************/
#include <iostream>
#include <functional>
#include <random>
#include <mutex>

int generateId() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1,1000);
    return dist(gen);
}

using Callback = std::function<void(const std::string&)>;
class EventSystem {
public:
    int subscribe (const std::string& eventName, Callback callback) {
        std::lock_guard<std::mutex> lock(m_mutex);
        int id = generateId();

        m_eventMap[eventName][id] = std::move(callback);
    }

    void publish(const std::string& eventName, const std::string& data) {
        std::lock_guard<std::mutex> lock(m_mutex);
    }

    void unsubscribe (int id) {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::unordered_map<int, Callback>::iterator map_it;
        for (auto it : m_eventMap) {
            map_it = std::find(it.second.begin(), it.second.end(), id);
        }
        
        // if (map_it != m_eventMap.end()) {
        //     m_eventMap.erase(id);
        // } else {
        //     std::cout << "The specified event ID does not exist" << std::endl;
        // }
    }

private:
    std::mutex m_mutex;
    std::unordered_map<std::string , std::unordered_map<int, Callback>> m_eventMap;
};

int main() {
    EventSystem events;

    auto id1 = events.subscribe("onClick", [](const std::string& data) {
        std::cout << "Handler 1: " << data << std::endl;
    });

    auto id2 = events.subscribe("onClick", [](const std::string& data) {
        std::cout << "Handler 2: " << data << std::endl;
    });

    auto id3 = events.subscribe("onHover", [](const std::string& data) {
        std::cout << "Hover handler: " << data << std::endl;
    });

    events.publish("onClick", "button clicked");
    // prints Handler 1 and Handler 2

    events.unsubscribe(id1);
    events.publish("onClick", "clicked again");
    // prints only Handler 2
}