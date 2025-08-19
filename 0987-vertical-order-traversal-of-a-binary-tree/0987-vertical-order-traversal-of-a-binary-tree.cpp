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
    void dfs(TreeNode*root,int col,int row, map<int,vector<pair<int,int>>>&mp)
    {
        if(root == NULL) return;
        mp[col].push_back(make_pair(row,root->val));
        if(root->left)dfs(root->left,col-1,row+1,mp);
        if(root->right)dfs(root->right,col+1,row+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>mp;
        dfs(root,0,0,mp);
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            auto nodes = it->second;
            sort(nodes.begin(),nodes.end());
            vector<int>temp;
            for(auto j:nodes)
            {
                temp.push_back(j.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};