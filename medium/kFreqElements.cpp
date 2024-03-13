#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        int numsLength = nums.size();
        for (int i = 0; i < numsLength; i++) {
            freqMap[nums[i]] += 1;
        }

        std::priority_queue<int> pq;
        for (const auto& pair: freqMap) {
            pq.push(pair.second);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        int kthFreq = pq.top();

        std::vector<int> returnArray;
        for (const auto& pair: freqMap) {
            if (pair.second - kthFreq >= 0) returnArray.push_back(pair.first);
        }

        return returnArray;
    }


    std::vector<int> topKFrequent1(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            freqMap[nums[i]]++;
        }

        std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& pair: freqMap) {
            buckets[pair.second].push_back(pair.first);
        } 

        std::vector<int> res;

        for (int i = n; i >= 0; i--) {
            if (res.size() >= k) break;
            if (!buckets.empty()) res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }

        return res;
    }
};