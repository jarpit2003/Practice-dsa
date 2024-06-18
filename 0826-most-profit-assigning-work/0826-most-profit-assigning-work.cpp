
class Solution {
public:
    static bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // If difficulty is the same, sort by profit in descending order
        }
        return a.first < b.first; // Otherwise, sort by difficulty in ascending order
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Step 1: Create pairs of (difficulty, profit)
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        }

        // Step 2: Sort the pairs using the comparator function
        sort(jobs.begin(), jobs.end(), comparePairs);

        // Step 3: Sort the worker array
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int best = 0;  // Best profit so far
        int j = 0;  // Index for jobs

        // Step 4: Iterate over each worker and assign the best possible job
        for (int i = 0; i < worker.size(); ++i) {
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                best = max(best, jobs[j].second);
                ++j;
            }
            maxProfit += best;
        }

        return maxProfit;
    }
};



