#include <limits>

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
    bool isValidBST(TreeNode* root) {
        double pos_inf = std::numeric_limits<double>::infinity();
        double neg_inf = -pos_inf;

        return isValidBST(root->left, neg_inf, root->val) 
            && isValidBST(root->right, root->val, pos_inf); 
    }
private:
    bool isValidBST(TreeNode* root, double lower_bound, double upper_bound) {
        if (!root) return true;
        if (root->val > lower_bound && root->val < upper_bound) {
            return isValidBST(root->left, lower_bound, root->val) 
                && isValidBST(root->right, root->val, upper_bound);
        }
        return false;
    }
};