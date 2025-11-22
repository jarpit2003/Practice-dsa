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
int maxdep = 0;
    int solve(TreeNode*root)
    {
        if(root==NULL)return 0;
       int l = solve(root->left);
       int r = solve(root->right);
       maxdep = max(maxdep,1+max(l,r));
        return 1+max(l,r);
    }
    int maxDepth(TreeNode* root) {
        solve(root);
        return maxdep;
    }
};