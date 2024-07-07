class Solution {
public:
    // The function calculates the total number of water bottles one can drink,
    // given the initial number of bottles and the number of empty bottles required
    // to exchange for a new full water bottle.
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles; // Total bottles drunk includes initial bottles
        while (numBottles >= numExchange) {
            // Each time the loop runs, we can exchange 'numExchange' empty bottles
            // for one new full bottle. In the process, we effectively lose
            // 'numExchange - 1' empty bottles since we get one full bottle back.
            numBottles -= (numExchange - 1);

            // Increment the total drunk since we gained one bottle by exchanging
            totalDrunk++;

            // No change in amount of code here, but using loop condition for clarity
        }
        return totalDrunk;
    }
};