class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*traverse where there is achange there make a chnge increase the count*/
       int xorResult = start ^goal;
        return __builtin_popcount(xorResult);
    }
};