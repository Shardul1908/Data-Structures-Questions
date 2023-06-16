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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs_tree1;
        vector<int> leafs_tree2;

        getLeafArr(root1, leafs_tree1);
        getLeafArr(root2, leafs_tree2);

        int len1 = leafs_tree1.size();
        int len2 = leafs_tree2.size();
        if(len1 != len2) {
            return false;
        }
        
        for(int i = 0;i < len1;i++) {
            if(leafs_tree1[i] != leafs_tree2[i]) {
                return false;
            }
        }

        return true;
    }

    void getLeafArr(TreeNode* root, vector<int>& leafArr) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            leafArr.push_back(root->val);
            return;
        }

        getLeafArr(root->left, leafArr);
        getLeafArr(root->right, leafArr);
    }
};