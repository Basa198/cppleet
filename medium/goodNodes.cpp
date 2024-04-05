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
    int goodNodes(TreeNode* root) {
        int result = 0;
        goodNodes(root, root->val, result);
        return result; 
    }
private:
    int goodNodes(TreeNode* root, int max, int& result) {
        if (!root) return 0;

        if (root->val >= max) {
            result++;
            max = root->val;
        }

        goodNodes(root->left, max, result);
        goodNodes(root->right, max, result); 
    }
};