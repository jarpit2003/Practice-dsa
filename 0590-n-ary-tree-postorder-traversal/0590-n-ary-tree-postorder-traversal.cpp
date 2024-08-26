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
        if (root == nullptr) return {};

        vector<int> result;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            result.push_back(node->val);
            for (Node* child : node->children) {
                st.push(child);
            }
        }

        // Reverse the result to get the correct postorder traversal
        reverse(result.begin(), result.end());
        return result;
    }
};
