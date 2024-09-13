class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;

        // Count the number of set bits (1s) manually
        while (xorResult > 0) {
            count += (xorResult & 1); // Increment count if the least significant bit is 1
            xorResult >>= 1;          // Right shift to process the next bit
        }

        return count;
    }
};
