#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;

        int size = nums.size();
        for (int i = 0; i < size; i++) pq.push(nums[i]);

        while (pq.size() > this->k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        std::cout << "HERE" << pq.top() << '\n';
        if (pq.size() > this->k) pq.pop();
        
        return pq.top();
    }

private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};


int main() {
    std::vector<int> a1 = {4, 2, 3, 8};
    KthLargest k = KthLargest(1, a1); 

    std::cout << k.add(10) << '\n';
    std::cout << k.add(11) << '\n';
    std::cout << k.add(11) << '\n';
}


