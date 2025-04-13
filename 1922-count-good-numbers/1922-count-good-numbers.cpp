class Solution {
public:
    int mod = 1000000007;

    // Recursive function for modular exponentiation
    long long int pow(int base, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return base % mod;
        }

        // Modular exponentiation with recursion
        long long halfpow = pow(base, n / 2) % mod;  // Recursive call
        long long result = (halfpow * halfpow) % mod;  // Square the halfpower and take modulo

        if (n % 2 == 1) {
            result = (result * base) % mod;  // If n is odd, multiply by base
        }

        return result;
    }

    // Function to calculate the number of good numbers
    int countGoodNumbers(long long n) {
        long long ans = pow(20, n / 2);  // Calculate 20^(n/2) mod 1000000007
        
        // Multiply by 5 only if n is odd
        if (n % 2 == 1) {
            ans = (ans * 5) % mod;
        }
        
        return ans;  // Return the result modulo 1000000007
    }
};
