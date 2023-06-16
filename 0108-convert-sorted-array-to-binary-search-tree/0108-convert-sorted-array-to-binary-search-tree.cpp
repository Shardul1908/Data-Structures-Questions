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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_util(nums, 0, (nums.size()-1)); 
    }

    TreeNode* sortedArrayToBST_util(vector<int>& nums, int start_idx, int end_idx) {
        if(start_idx > end_idx) {
            return nullptr;
        }

        int mid = (start_idx + end_idx)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST_util(nums, start_idx, mid-1);
        root->right = sortedArrayToBST_util(nums, mid+1, end_idx);

        return root;
    }
};