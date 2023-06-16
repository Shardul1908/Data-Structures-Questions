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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        bool res = true;
        isUnivalTree_util(root, val, res);

        return res;
    }

    void isUnivalTree_util(TreeNode* root, int val, bool& res) {
        if(root == nullptr) {
            return;
        }

        if(root->val != val) {
            res = false;
            return;
        }            
        
        isUnivalTree_util(root->left, val, res);
        isUnivalTree_util(root->right, val, res);
    
    }
};