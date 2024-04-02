#include <string>
#include <iostream>
#include <vector>

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        times.push_back(timestamp);
        keyValues.push_back({key, value});
    }
    
    std::string get(std::string key, int timestamp) {
        int index = findIndex(timestamp);

        while (index >= 0 && keyValues[index][0] != key) --index;

        return index >= 0 ? keyValues[index][1] : "";
    }

private:
    std::vector<int> times;
    std::vector<std::vector<std::string>> keyValues;

    int findIndex(int timestamp) {
        int l = 0;
        int r = times.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (times[mid] == timestamp) return mid;
            else if (times[mid] < timestamp) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }
};


int main() {
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    std::cout << obj->get("foo", 1) << '\n';
    std::cout << obj->get("foo", 3) << '\n';
    obj->set("foo", "bar2", 4);
    std::cout << obj->get("foo", 4) << '\n';
    std::cout << obj->get("foo", 5) << '\n';
}