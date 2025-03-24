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
int maxsum = 0;
int depth(TreeNode*root)
{
    if (root==NULL) return 0;
    int leftnode = depth(root->left);
    int rightnode = depth(root->right);
    maxsum = max(maxsum,leftnode+rightnode+root->val);
    return root->val;
}
    int maxPathSum(TreeNode* root) {
        depth(root);
        return maxsum;
    }
};