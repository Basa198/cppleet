#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        int n = triplets.size();
        std::vector<int> cur_triplet(3);

        for (int i = 0; i < n; i++) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                cur_triplet[0] = std::max(triplets[i][0], cur_triplet[0]);
                cur_triplet[1] = std::max(triplets[i][1], cur_triplet[1]);
                cur_triplet[2] = std::max(triplets[i][2], cur_triplet[2]);
            }
            if (cur_triplet[0] == target[0] && cur_triplet[1] == target[1] && cur_triplet[2] == target[2])
                return true;
        }

        return cur_triplet[0] == target[0] && cur_triplet[1] == target[1] && cur_triplet[2] == target[2]; 
    }

    bool mergeTripletsTwo(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        int n = triplets.size();
        std::unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;

            for (int j = 0; j < 3; j++) {
                if (triplets[i][j] == target[j]) s.insert(j);
            }
        }

        return s.size() == 3;
    }
};