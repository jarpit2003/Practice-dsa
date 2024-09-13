class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*traverse where there is achange there make a chnge increase the count*/
       int xorResult = start ^goal;
        int count = 0;
        while(xorResult){
            xorResult &= (xorResult - 1);
            count++;
        }
     return count;
    }
};