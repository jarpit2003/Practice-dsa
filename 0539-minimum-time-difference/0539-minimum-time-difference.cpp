class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Step 1: Convert time strings to minutes
        vector<int> minutesList;
        
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            minutesList.push_back(hours * 60 + minutes);
        }
        
        // Step 2: Sort the time points in terms of minutes
        sort(minutesList.begin(), minutesList.end());
        
        // Step 3: Initialize the minimum difference as a large number
        int minDiff = INT_MAX;
        
        // Step 4: Calculate the minimum difference between consecutive times
        for (int i = 1; i < minutesList.size(); ++i) {
            minDiff = min(minDiff, minutesList[i] - minutesList[i - 1]);
        }
        
        // Step 5: Handle the wrap-around case (between the last and the first time point)
        // Circular difference: 1440 (total minutes in a day) - last_time + first_time
        minDiff = min(minDiff, 1440 - minutesList.back() + minutesList[0]);
        
        return minDiff;
    }
};
