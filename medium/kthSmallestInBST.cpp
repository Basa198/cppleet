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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int count = -1;
        kthSmallest(root->left, k, count, result);
        if (result != -1) return result;
        count++;
        if (count == k) return root->val;
        kthSmallest(root->right, k, count, result);
        return result;
    }
private:
    void kthSmallest(TreeNode* root, int k, int& count, int& result) {
        if (!root) return;

        kthSmallest(root->left, k, count, result);

        if (count == -1 && !root->left) count = 1;
        else count++;

        if (count == k) {
            result = root->val;
            return;
        }

        kthSmallest(root->right, k, count, result);
    }

};