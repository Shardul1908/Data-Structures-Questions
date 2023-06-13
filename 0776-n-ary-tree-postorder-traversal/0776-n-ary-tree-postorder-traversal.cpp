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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == nullptr) {
            return res;
        }
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* curr = st.top();
            st.pop();

            vector<Node*>& children = curr->children;
            for(int i = 0;i < children.size(); i++) {
                st.push(children[i]);
            }
            res.push_back(curr->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};