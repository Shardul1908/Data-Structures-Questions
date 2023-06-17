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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> diffs;
        bool res = false;

        findTarget_util(root, k, diffs, res);
        return res;
    }

    void findTarget_util(TreeNode* root, int k, unordered_set<int>& diffs, bool& res) {
        if(root == nullptr) {
            return;
        }
        if(diffs.find(root->val) != diffs.end()) {
            res = true;
            return;
        }

        diffs.insert(k - root->val);
        findTarget_util(root->left, k, diffs, res);
        findTarget_util(root->right, k, diffs, res);

    }
};