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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if(curr->left != nullptr)
                st.push(curr->left);
            if(curr->right != nullptr)
                st.push(curr->right);
            res.push_back(curr->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};