#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
    }
    
    int get(int key) {
        if (nodeMap.find(key) != nodeMap.end()) {
            auto it = nodeMap[key];
            nodeMap.erase(key);
            int val = (*it).second;
            cache.erase(it);
            cache.push_back({ key, val });
            nodeMap.insert({ key, std::prev(cache.end()) });

            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (nodeMap.find(key) != nodeMap.end()) {
            auto it = nodeMap[key];
            cache.erase(it);
            nodeMap.erase(key);
        }
        if (cache.size() == capacity) {
            int key_to_delete = cache.front().first;
            nodeMap.erase(key_to_delete);
            cache.pop_front();
        }

        cache.push_back({ key, value });
        auto end = cache.end();
        nodeMap.insert({ key, std::prev(end) });
    }
private:
    int capacity;
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> nodeMap;
};

int main() {
    LRUCache* c = new LRUCache(2);
    c->put(2, 1);
    c->put(1, 1);
    c->get(2);
    c->put(4, 1);
    c->get(1);
    c->get(2);
}