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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        queue<TreeNode*> qe;
        qe.push(root);
        
        while(!qe.empty()) {
            int level_size = qe.size();
            double sum = 0;

            for(int i = 0;i<level_size;i++) {
                TreeNode* curr = qe.front();
                qe.pop();
                // cout << curr->val << " ";
                sum += curr->val;

                if(curr->left != nullptr)
                    qe.push(curr->left);
                if(curr->right != nullptr)
                    qe.push(curr->right);
            }
            // cout << "\n" << sum << " " << level_size << "\n";
            res.push_back(sum/level_size);
        }
        
        return res;
    }

};