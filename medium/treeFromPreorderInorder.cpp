#include <stack>
#include <set>
#include <vector>
#include <cmath>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        buildTree(root, preorder, inorder);
        return root;
    }
private:
    void buildTree(TreeNode* root, std::vector<int>& preorder, std::vector<int>& inorder) {
        std::stack<std::pair<TreeNode*, int>> stk; 
        int root_index = findIndex(inorder, root->val);
        stk.push({root, root_index});
        std::set<int> traversed_values;
        traversed_values.insert(root->val);

        int arr_length = preorder.size();
        int i = 1;
        while (i < arr_length) {
            TreeNode* child_candidate = new TreeNode(preorder[i]);
            int child_index = findIndex(inorder, preorder[i]);

            while (!stk.empty()) {
                TreeNode* parent_candidate = stk.top().first;
                int parent_index = stk.top().second;

                int increment = parent_index - child_index > 0 ? 1 : -1;
                bool isChild = true;
                for (int j = child_index + increment; j != parent_index; j += increment) {
                    if (traversed_values.find(inorder[j]) != traversed_values.end()) {
                        isChild = false;
                        break;
                    }
                }

                if (isChild) {
                    if (parent_index > child_index) {
                        parent_candidate->left = child_candidate;
                    } else {
                        parent_candidate->right = child_candidate;
                        stk.pop();
                    }
                    traversed_values.insert(child_candidate->val);
                    stk.push({child_candidate, child_index});    
                    break;
                }
                stk.pop();
            }
            i++;
        }
    }

    int findIndex(std::vector<int> a, int target) {
        int length = a.size();
        for (int i = 0; i < length; i++) {
            if (a[i] == target) return i;
        }
        return -1;
    }
};


int main() {
    std::vector<int> preorder {3, 9, 20, 15, 7};
    std::vector<int> inorder {9, 3, 15, 20, 7};
    Solution sol; 
    sol.buildTree(preorder, inorder);
}