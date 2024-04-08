#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> curr;
        combinationSum(candidates, combinations, curr, target, 0);    
        return combinations;
    }
private:
    void combinationSum(std::vector<int>& candidates, std::vector<std::vector<int>>& combinations, std::vector<int>& curr, int target, int index) {
        if (target == 0) {
            combinations.push_back(curr);
            return;
        }
        int cand_size = candidates.size();
        for (int i = index; i < cand_size; i++) {
            int j = 1;
            while (target - j * candidates[i] >= 0) {
                curr.push_back(candidates[i]);
                combinationSum(candidates, combinations, curr, target - j * candidates[i], i + 1);
                j++;
            }
            while (j > 1) {
                curr.pop_back();
                j--;
            }
        }
    }
};