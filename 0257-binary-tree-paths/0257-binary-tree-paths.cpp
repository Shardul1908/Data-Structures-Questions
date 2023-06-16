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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path = "";

        binaryTreePaths_util(root, path, res);
        return res;
    }

    void binaryTreePaths_util(TreeNode* root, string path, vector<string>& res) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        
        path += to_string(root->val);
        path += "->";

        binaryTreePaths_util(root->left, path, res);
        binaryTreePaths_util(root->right, path, res);
        
    }
};