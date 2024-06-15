class Solution {
public:
    static bool com(pair<int,int>& a, pair<int,int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        
        // Create pairs of (profit, capital) and sort by capital ascending, profit descending
        for (int i = 0; i < n; ++i) {
            projects[i] = {profits[i], capital[i]};
        }
        
        // Sort projects by their capital requirement
        sort(projects.begin(), projects.end(), com);
        
        priority_queue<int> pq; // max heap to store profits
        
        int i = 0;
        while (k > 0) {
            // Add all projects whose capital <= current capital `w` to the priority queue
            while (i < n && projects[i].second <= w) {
                pq.push(projects[i].first); // push profit into max heap
                i++;
            }
            
            // If we have projects we can invest in (pq is not empty), pick the one with maximum profit
            if (!pq.empty()) {
                w += pq.top(); // add the maximum profit to capital
                pq.pop(); // remove it from the heap
                k--; // decrement remaining projects to pick
            } else {
                break; // no more projects we can invest in
            }
        }
        
        return w;
    }
};