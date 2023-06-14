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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        dfs(p,q,result);

        return result;
    }

    void dfs(TreeNode* p, TreeNode* q, bool& result) {
        if(!p && !q) {
            return;
        }

        if(!p || !q) {
            result = false;
            return;
        }

        if(p->val != q->val) {
            result = false;
            return;
        }

        dfs(p->left,q->left,result);
        dfs(p->right,q->right,result);
    }
};