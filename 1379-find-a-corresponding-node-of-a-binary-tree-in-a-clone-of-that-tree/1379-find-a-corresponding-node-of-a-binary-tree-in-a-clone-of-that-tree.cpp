/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr && cloned == nullptr) {
            return nullptr;
        }

        if(original == target) {
            return cloned;
        }

        TreeNode* leftNode = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rightNode = getTargetCopy(original->right, cloned->right, target);
        
        if(leftNode != nullptr) {
            return leftNode;
        }
        
        if(rightNode != nullptr) {
            return rightNode;
        }

        return nullptr;
    }


};