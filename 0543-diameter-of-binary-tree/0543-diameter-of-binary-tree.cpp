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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        depth(root, res);
        return res;
    }

    int depth(TreeNode* root, int& res) {
        if(root == NULL) {
            return 0;
        }

        int left_depth = depth(root->left, res);
        int right_depth = depth(root->right, res);

        res = max(res, (left_depth + right_depth));
        return 1 + max(left_depth,right_depth);
    }
};