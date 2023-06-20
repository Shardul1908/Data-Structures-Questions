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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int level_size = que.size();
            res = 0;

            for(int i = 0;i < level_size;i++) {
                TreeNode* curr = que.front();
                que.pop();

                res += curr->val;
                if(curr->left != nullptr)
                    que.push(curr->left);
                if(curr->right != nullptr)
                    que.push(curr->right);
            }
        }

        return res;

    }
};