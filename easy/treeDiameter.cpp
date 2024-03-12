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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        maxDepth(root, result);
        return result;
    }

private:
    int maxDepth(TreeNode* node, int& result) {
        if (!node) return 0;

        int left = maxDepth(node->left, result);
        int right = maxDepth(node->right, result);

        result = std::max(result, left + right);

        return 1 + std::max(left, right);
    }
};