
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_value = nums[0];
        int max_value = nums[0];
        
        // Finding min and max values: O(n)
        for (int num : nums) {
            if (num < min_value) {
                min_value = num;
            }
            if (num > max_value) {
                max_value = num;
            }
        }
        
        int gcd = calculateGCD(min_value, max_value); // O(log(min_value + max_value))
        return gcd;
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


