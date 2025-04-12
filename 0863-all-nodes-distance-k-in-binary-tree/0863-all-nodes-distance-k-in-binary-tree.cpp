/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*>parent;
void BFS( TreeNode* target,int k,vector<int>&result)
{
    queue<TreeNode*>q;
    q.push(target);
    std::unordered_set<TreeNode*> visited;
    visited.insert(target);
    while(!q.empty())
    {
        int n = q.size();
        if(k==0)
        {
            break;
        }
        while(n--)
        {
            TreeNode*curr = q.front();
            q.pop();
            if(curr->left!=NULL&&!visited.count(curr->left))
            {
                q.push(curr->left);
                visited.insert(curr->left);
            }
            if(curr->right!=NULL&&!visited.count(curr->right))
            {
                q.push(curr->right);
                visited.insert(curr->right);
            }
            if(parent.count(curr)&&!visited.count(parent[curr]))
            {
                q.push(parent[curr]);
                visited.insert(parent[curr]);
            }
        }
        k--;
    }
    while(!q.empty())
    {
        TreeNode*temp = q.front();
        q.pop();
        result.push_back(temp->val);
    }
}
void inorder_to_declare_parent(TreeNode*root)
        {
            if(!root) return;
            if(root->left!=NULL)
            {
                parent[root->left] = root;
                inorder_to_declare_parent(root->left); 
            }
            if(root->right!=NULL)
            {
                parent[root->right] = root;
                inorder_to_declare_parent(root->right); 
            }
        }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>result;
        inorder_to_declare_parent(root);
        BFS(target,k,result);
        return result;
    }
};