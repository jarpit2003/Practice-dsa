class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = sqrt(c); i >= 0; i--) {
            int jSquared = c - i * i;
            int j = sqrt(jSquared);
            if(j * j == jSquared) {
                return true;
            }
        }
        return false;
    }
};




