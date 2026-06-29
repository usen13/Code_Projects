/***************************************************** 
LRU (Least Recently Used) cache with:

Fixed capacity set at construction
get(key) — returns the value if it exists, updates it as most recently used, returns -1 if not found
put(key, value) — inserts or updates a key. If at capacity, evicts the least recently used entry first
Operations at O(1)
*****************************************************/
#include <iostream>
#include <unordered_map>
#include <algorithm>

class LRUCache {
    // Your implementation
public:
    LRUCache(int capacity) {
        m_cache.reserve(capacity);
        this->capacity = capacity;
    };

    int get (int key) {
        auto it = m_cache.find(key);

        if (it != m_cache.end()) {
            it->second.second++;
            // For loop to decrement the usage of other values stored in the map
            for (auto nested_it : m_cache) {
                if (it->first == nested_it.first) {
                    continue;
                }
                nested_it.second.second--;
            }
            return it->second.first;
        }
        return -1;
    } 

    void put (int key, int value) {
        if (m_cache.size() == capacity) {
            auto min_it = std::min_element(m_cache.begin(), m_cache.end(), [] (const auto l, const auto r) {
                return l.second.second < r.second.second;
            });
            std::cout << "Evicted :" << min_it->first << std::endl; 
            m_cache.erase(min_it->first);
            m_cache[key] = {value, 0};
        } else {
            m_cache[key] = {value, 0};
        }
    }

private:
    std::unordered_map<int, std::pair<int, int>> m_cache;
    int capacity;
};

int main() {
    LRUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    std::cout << cache.get(1) << std::endl;  // 10  (1 is now most recent)
    cache.put(4, 40);              // evicts 2 (least recently used)
    std::cout << cache.get(2) << std::endl;  // -1  (evicted)
    std::cout << cache.get(3) << std::endl;  // 30
    std::cout << cache.get(4) << std::endl;  // 40
}