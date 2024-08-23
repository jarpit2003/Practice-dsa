class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize the result fraction
        int numerator = 0, denominator = 1;
        int i = 0;
        int n = expression.size();
        
        while (i < n) {
            // Parse the sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = expression[i] == '-' ? -1 : 1;
                i++;
            }
            
            // Parse the numerator
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;
            
            // Skip the '/'
            i++;
            
            // Parse the denominator
            int denom = 0;
            while (i < n && isdigit(expression[i])) {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }
            
            // Add the fraction to the result
            numerator = numerator * denom + num * denominator;
            denominator *= denom;
            
            // Reduce the fraction by gcd
            int gcd_val = gcd(abs(numerator), denominator);
            numerator /= gcd_val;
            denominator /= gcd_val;
        }
        
        // Return the result as a fraction
        return to_string(numerator) + "/" + to_string(denominator);
    }
};