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
    bool isValidBST(TreeNode* root) {
        stack<int> elems;
        bool res = true;

        inOrderTrav(root, elems, res);
        return res;
    }

    void inOrderTrav(TreeNode* root,stack<int>& elems, bool& res) {
        if(root == nullptr) {
            return;
        }

        inOrderTrav(root->left, elems, res);
        if(!elems.empty()) {
            if(elems.top() >= root->val) {
                res = false;
                return;
            }
        }
        elems.push(root->val);
        inOrderTrav(root->right, elems, res);
    }
};