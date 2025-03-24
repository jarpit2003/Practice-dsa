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
int maxdiameter = 0;
    int depth(TreeNode*root)
    {
        if (root==NULL) return 0;
        int leftdia = depth(root->left);
        int rightdia = depth(root->right);
        maxdiameter = max(maxdiameter,leftdia+rightdia);
        return 1+max(leftdia,rightdia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxdiameter;
    }
};