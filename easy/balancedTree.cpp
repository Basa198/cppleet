#include <algorithm>

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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedPrivate(root, height);
    }

private:
    bool isBalancedPrivate(TreeNode* node, int& height) {
        if (!node) {
            return true;
        }
        
        int left = 0;
        int right = 0;

        if (!isBalancedPrivate(node->left, left) || !isBalancedPrivate(node->right, right)) return false;
        if (abs(left - right) > 1) return false;

        height = 1 + std::max(left, right);
        return true;
    }
};