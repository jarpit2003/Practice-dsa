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
    TreeNode*traverse(TreeNode*root,int &k)
    {
        if(root==NULL) return new TreeNode(k);
       else if(root->val>k) root->left = traverse(root->left,k);
       else if(root->val<k) root->right = traverse(root->right,k);
       return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0 ;i<preorder.size();i++)
        {
          root = traverse(root,preorder[i]);
        }
        return root;
    }
};