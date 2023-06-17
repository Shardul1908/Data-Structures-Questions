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
    string tree2str(TreeNode* root) {
        string res = "";
        convert(root, res);

        int len = res.length();
        res = res.substr(1, (len-2));
        return res;
    }

    void convert(TreeNode* root, string& str) {
        if(root == nullptr) {
            return;
        }
        str += "(";
        str += to_string(root->val);
        if(root->left == nullptr && root->right != nullptr) {
            str += "()";
        }
        convert(root->left, str);
        convert(root->right, str);
        str += ")";
    }
};