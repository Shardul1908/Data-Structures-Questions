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
    int findTilt(TreeNode* root) {
        int sum = 0;

        tilt(root, sum);
        return sum;
    }

    int tilt(TreeNode* root, int& sum) {
        if(root == nullptr) {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int leftVal = tilt(root->left, sum);
        int rightVal = tilt(root->right, sum);

        int tilt_val = abs(leftVal - rightVal);
        
        sum += tilt_val;
        return (root->val + leftVal + rightVal);
    }
};