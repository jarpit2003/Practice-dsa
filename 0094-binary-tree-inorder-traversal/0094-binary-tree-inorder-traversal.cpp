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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(root==NULL) return inorder;
        TreeNode*current = root;
        stack<TreeNode*>st;
        while(current!=NULL||!st.empty())
        {
            while(current!=NULL)
        {
                st.push(current);
                current = current->left;
        }
            current = st.top();         
            inorder.push_back(current->val);
            st.pop();
            current = current->right;
        }
        return inorder;
    }
};