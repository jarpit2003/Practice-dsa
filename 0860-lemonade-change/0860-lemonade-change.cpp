class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fived = 0, tend = 0;
        
        for (int bill : bills) {
            switch(bill) {
                case 5:
                    fived++;
                    break;
                    
                case 10:
                    if (fived > 0) {
                        fived--;
                        tend++;
                    } else {
                        return false;  // Can't provide change
                    }
                    break;
                    
                case 20:
                    if (tend > 0 && fived > 0) {
                        tend--;
                        fived--;
                    } else if (fived >= 3) {
                        fived -= 3;
                    } else {
                        return false;  // Can't provide change
                    }
                    break;
                    
                default:
                    // Handle unexpected values if needed
                    return false;
            }
        }
        
        return true;
    }
};
