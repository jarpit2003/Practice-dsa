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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool ltr = true;
        while(!q.empty())
        {
            int ls = q.size();
            vector<int>level;
            for(int i = 0;i<ls;i++)
            {
               TreeNode*current = q.front();
               q.pop();
               level.push_back(current->val);
                if(current->left)
                {
                    q.push(current->left);
                }
               if(current->right)
                {
                    q.push(current->right);
                }
            }
            if(ltr==false)
            {
                reverse(level.begin(),level.end());
            }
              result.push_back(level);
              ltr = !ltr;
        }
        return result;
    }
};