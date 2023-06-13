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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* curr = st.top();
            st.pop();

            res.push_back(curr->val);
            vector<Node*>& children = curr->children;
            for(int i = children.size() - 1;i>=0;--i) {
                st.push(children[i]);
            }

        }

        return res;
    }
};