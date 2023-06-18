/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int prev_val = -1;
        int min_res = INT_MAX;

        solve(root, prev_val, min_res);
        return min_res;
    }

    void solve(TreeNode* root, int& prev_val, int& min_res) {
        if(root == nullptr) {
            return;
        }

        solve(root->left , prev_val, min_res);
        if(prev_val != -1) {
            min_res = min(min_res, (root->val - prev_val));
        }
        prev_val = root->val;
        solve(root->right, prev_val, min_res);
    }

    
};