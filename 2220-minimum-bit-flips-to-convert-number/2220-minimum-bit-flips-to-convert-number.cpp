class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*traverse where there is achange there make a chnge increase the count*/
        int count = 0;
        bitset<32>bin1(start);
        bitset<32>bin2(goal);
        for(int i = 0;i<32;++i){
            if(bin1[i]!=bin2[i]){
                count++;
            }
        }
     return count;
    }
};