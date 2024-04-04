#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        levelOrder(root, 0);
        return nodeArray;
    }
private:
    std::vector<std::vector<int>> nodeArray;

    void levelOrder(TreeNode* root, int level) {
       if (!root) return;

       if (nodeArray.size() > level) {
            nodeArray[level].push_back(root->val);
       } else {
            nodeArray.push_back({root->val}); 
       }

       levelOrder(root->left, level + 1);
       levelOrder(root->right, level + 1);
    }
};