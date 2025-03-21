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
    TreeNode* treverse(TreeNode*root,int k)
    {
        if(root==NULL) return new TreeNode(k);
        else if(root->val>k) root->left = treverse(root->left,k);
        else if(root->val<k) root->right = treverse(root->right,k);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0;i<preorder.size();i++)
        {
            root = treverse(root,preorder[i]);
        }
        return root;
    }
};