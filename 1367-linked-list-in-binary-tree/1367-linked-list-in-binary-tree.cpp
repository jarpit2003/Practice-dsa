/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // Helper function to check if the linked list starting from 'head' matches a path in the tree starting from 'root'
    bool dfs(ListNode* head, TreeNode* root) {
        // If we've successfully matched all nodes in the linked list
        if (!head) return true;
        // If the tree node is null or the values don't match, return false
        if (!root || root->val != head->val) return false;
        // Continue matching the next linked list node in either the left or right subtree
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    
    // Main function to check if there is any downward path that matches the linked list
    bool isSubPath(ListNode* head, TreeNode* root) {
        // If the tree is null, no path can exist
        if (!root) return false;
        // Check if the linked list matches starting from the current root node
        // or search recursively in the left and right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};