class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fived = 0, tend = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                fived++;
            } 
            else if (bill == 10) {
                if (fived > 0) {
                    fived--;
                    tend++;
                } else {
                    return false;  // Can't provide change
                }
            } 
            else if (bill == 20) {
                // Prefer giving one $10 and one $5 as change
                if (tend > 0 && fived > 0) {
                    tend--;
                    fived--;
                } 
                // If no $10, give three $5 bills
                else if (fived >= 3) {
                    fived -= 3;
                } 
                else {
                    return false;  // Can't provide change
                }
            }
        }
        
        return true;
    }
};
