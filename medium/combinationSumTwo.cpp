#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> combinations; 
        std::vector<int> curr;
        std::sort(candidates.begin(), candidates.end());
        combinationSum(candidates, combinations, curr, target, 0);
        return combinations;
    }
private:
    void combinationSum(std::vector<int>& sorted_cands, 
        std::vector<std::vector<int>>& combinations, 
        std::vector<int>& curr, int target, int index) {
        //
        if (target == 0) {
            combinations.push_back(curr);
            return;
        }
        int cands_size = sorted_cands.size();
        for (int i = index; i < cands_size; i++) {
            if (i > index && sorted_cands[i] == sorted_cands[i - 1]) continue;
            if (sorted_cands[i] > target) return;
            
            curr.push_back(sorted_cands[i]);
            combinationSum(sorted_cands, combinations, curr, target - sorted_cands[i], i + 1);
            curr.pop_back();
        }
    }
};