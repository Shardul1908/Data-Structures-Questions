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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;

        sumPath(root,0, res);
        return res;
    }

    void sumPath(TreeNode* root, int sum, int& res) {
        if(root == nullptr){
            return;
        }    

        sum = sum << 1 | root->val;
        if(root->left == nullptr && root->right == nullptr) {
            res += sum;
        }

        sumPath(root->left, sum, res);
        sumPath(root->right, sum, res);
    }
};