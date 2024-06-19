class Solution {
public:
    int canmakebouque(const vector<int>& bloomDay, int mid, int k) {
        int bouqCount = 0;
        int consCount = 0;

        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= mid) {
                consCount++;
            } else {
                consCount = 0;
            }
            if (consCount == k) {
                bouqCount++;
                consCount = 0;
            }
        }
        return bouqCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Use long long to avoid overflow
        if (static_cast<long long>(m) * k > bloomDay.size()) {
            return -1;
        }

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canmakebouque(bloomDay, mid, k) >= m) {
                minDay = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return minDay;
    }
};

