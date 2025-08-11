class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> s;
        TreeNode* lastVisited = nullptr;
        TreeNode* current = root;
        
        while (!s.empty() || current != nullptr) {
            if (current != nullptr) {
                s.push(current);
                current = current->left;
            } else {
                TreeNode* node = s.top();
                // If right child exists and hasn't been visited, go right.
                if (node->right != nullptr && lastVisited != node->right) {
                    current = node->right;
                } else {
                    ans.push_back(node->val);
                    lastVisited = node;
                    s.pop();
                }
            }
        }
        
        return ans;
    }
};
