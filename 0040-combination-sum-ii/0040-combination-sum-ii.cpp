class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result) {
        // Base case: if target is 0, we've found a valid combination
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        // Iterate over candidates starting from index idx
        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            // If the current candidate exceeds the target, no point in continuing
            if (candidates[i] > target) {
                break;
            }
            
            // Include the current candidate in the combination
            curr.push_back(candidates[i]);
            
            // Recursively call solve with the remaining target and next index
            solve(candidates, target - candidates[i], curr, i + 1, result);
            
            // Backtrack: remove the last added element
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        // Sort candidates to handle duplicates
        sort(candidates.begin(), candidates.end());
        
        // Start the backtracking process
        solve(candidates, target, curr, 0, result);
        
        return result;
    }
};
