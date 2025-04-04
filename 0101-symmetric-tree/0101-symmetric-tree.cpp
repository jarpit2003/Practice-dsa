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
bool system(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;  // Both nodes are NULL, symmetric
    if (p == NULL || q == NULL) return false;  // One node is NULL, not symmetric
    if (p->val != q->val) return false;  // Values don't match, not symmetric   
    // Recursively check left and right subtrees
    return system(p->left, q->right) && system(p->right, q->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return system(root->left,root->right);
    }
};