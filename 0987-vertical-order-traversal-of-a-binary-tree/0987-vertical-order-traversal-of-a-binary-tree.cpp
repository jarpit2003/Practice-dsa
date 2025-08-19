class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // This will store the result
        vector<vector<int>> ans;
        // Map to store nodes by columns, each column stores pairs of (row, value)
        map<int, vector<pair<int, int>>> mp;
        
        // Start DFS traversal with initial column 0 and row 0
        dfs(root, 0, 0, mp);
        
        // Extract and sort the values for each column
        for (auto& [col, nodes] : mp) {
            sort(nodes.begin(), nodes.end()); // Sort by row first, then value
            vector<int> columnValues;
            for (auto& [row, val] : nodes) {
                columnValues.push_back(val);
            }
            ans.push_back(columnValues);
        }
        
        return ans;
    }

private:
    void dfs(TreeNode* node, int row, int col, map<int, vector<pair<int, int>>>& mp) {
        if (node == nullptr) {
            return;
        }
        
        // Insert the node value along with its row into the map
        mp[col].push_back({row, node->val});
        
        // Recursively traverse left and right children
        dfs(node->left, row + 1, col - 1, mp);  // left child goes to col-1
        dfs(node->right, row + 1, col + 1, mp); // right child goes to col+1
    }
};