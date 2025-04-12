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
    void countingnode(TreeNode*root,int &count)
    {
        if(root == NULL) return;
        if(root!=NULL) count++;
        countingnode(root->left,count);
        countingnode(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        countingnode(root,count);
        return count;
    }
};