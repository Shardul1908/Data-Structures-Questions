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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }

        queue<TreeNode*> que;
        que.push(root);
        bool toggle = true;

        while(!que.empty()) {
            vector<int> level_data;
            int level_size = que.size();

            for(int i = 0;i < level_size;i++) {
                TreeNode* curr = que.front();
                que.pop();

                level_data.push_back(curr->val);
                
                if(curr->left != nullptr)
                    que.push(curr->left);
                if(curr->right != nullptr)
                    que.push(curr->right);
            }
            toggle = !toggle;
            if(toggle)
                reverse(level_data.begin(), level_data.end());
                
            res.push_back(level_data);
        }

        return res;
    }
};