class Solution {
public:
    int getSum(int a, int b) {
        int carry, sum;
        while (b != 0) {
            sum = a ^ b;        // Sum without carry
            carry = (a & b) << 1; // Carry
            a = sum;            // Update a to new sum
            b = carry;          // Update b to new carry
        }
        return a; // Return the final result which is the sum
    }
};
