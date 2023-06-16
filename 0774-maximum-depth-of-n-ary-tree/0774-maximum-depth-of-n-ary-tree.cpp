/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) {
            return 0;
        }

        vector<int> vec_max_depth;
        for(int i = 0; i < root->children.size(); i++) {
            vec_max_depth.push_back(maxDepth(root->children[i]));
        }

        if(vec_max_depth.size() == 0) {
            return 1;
        }
        return (*max_element(vec_max_depth.begin(), vec_max_depth.end()) + 1);
    }
};