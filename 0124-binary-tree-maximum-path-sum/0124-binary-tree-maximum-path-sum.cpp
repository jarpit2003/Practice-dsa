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
int maxsum = INT_MIN;
int depth(TreeNode*root)
{
    if (root==NULL) return 0;
    int leftnode = max(0,depth(root->left));
    int rightnode = max(0,depth(root->right));
    maxsum = max(maxsum,leftnode+rightnode+root->val);
    return root->val+max(leftnode,rightnode);
}
    int maxPathSum(TreeNode* root) {
        depth(root);
        return maxsum;
    }
};