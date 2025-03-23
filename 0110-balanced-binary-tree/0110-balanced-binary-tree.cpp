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
    int  checkheight(TreeNode*root)
    {
        if(root==NULL) return 0;
        int lf = checkheight(root->left);
        if(lf==-1) return -1;
        int rf = checkheight(root->right);
        if(rf==-1) return -1;
        if(abs(lf-rf)>1)return -1;
        return 1+max(lf,rf);
    }
    bool isBalanced(TreeNode* root) {
        
        return checkheight(root)!=-1;
    }
};