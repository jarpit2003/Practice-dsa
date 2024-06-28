

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_value = nums[0];
        int max_value = nums.back();
        int gcd = calculateGCD(min_value, max_value);
        return static_cast<int>(gcd);
    }

private:
    int calculateGCD(int A, int B) {
        while (A > 0 && B > 0) {
            if (A > B) {
                A = A % B;
            } else {
                B = B % A;
            }
        }
        return (A == 0) ? B : A;
    }
};
