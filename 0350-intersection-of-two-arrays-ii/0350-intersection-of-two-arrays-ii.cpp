class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> num3;
        
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    num3.push_back(nums1[i]);
                    // Once a match is found, break the inner loop to avoid duplicates
                    nums2[j] = -1;  // Mark this element as used
                    break;
                }
            }
        }
        return num3;
    }
};