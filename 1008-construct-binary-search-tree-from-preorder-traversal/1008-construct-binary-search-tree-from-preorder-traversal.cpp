class Solution {
public:
    int index = 0;  // Global index to track position in preorder array

    TreeNode* buildBST(vector<int>& preorder, int upperBound) {
        if (index >= preorder.size() || preorder[index] > upperBound) 
            return NULL;  // Stop if index is out of bounds or value exceeds limit

        TreeNode* root = new TreeNode(preorder[index++]);  // Create new node

        root->left = buildBST(preorder, root->val);   // Left subtree (values < root)
        root->right = buildBST(preorder, upperBound); // Right subtree (values > root)

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MAX);  // Call function with max boundary
    }
};
