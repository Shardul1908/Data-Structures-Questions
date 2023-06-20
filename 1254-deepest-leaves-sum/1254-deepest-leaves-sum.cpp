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
        unordered_map<int, int> mp;
        int max_depth = deepestLeavesSum_util(root, mp, 0);
        
        return mp[max_depth - 1];
    }

    int deepestLeavesSum_util(TreeNode* root, unordered_map<int,int>& mp, int depth) {
        if(root == nullptr) {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr) {
            if(mp.find(depth) == mp.end()) {
                mp[depth] = root->val;
            }else {
                mp[depth] += root->val;
            }
        }   

        int leftDepth = deepestLeavesSum_util(root->left, mp, depth + 1);
        int rightDepth = deepestLeavesSum_util(root->right, mp , depth + 1);

        return (max(leftDepth, rightDepth) + 1);
    }
};