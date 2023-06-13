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
    bool evaluateTree(TreeNode* root) {
        bool leftExp;
        bool rightExp;

        if(root->left != nullptr) {
            leftExp = evaluateTree(root->left);
        }
        if(root->right != nullptr) {
            rightExp = evaluateTree(root->right);
        }

        switch(root->val) {
            case 0:
                return false;
                break;
            case 1:
                return true;
                break;
            case 2:
                return (leftExp || rightExp);
                break;
            case 3:
                return (leftExp && rightExp);
                break;
        }

        return false;
    }
};