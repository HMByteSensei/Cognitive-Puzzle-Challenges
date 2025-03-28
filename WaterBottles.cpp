class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res{numBottles};
        while(numBottles >= numExchange) {
            numBottles = numBottles / numExchange;
            res += numBottles;
            numBottles += (res-numBottles) % numExchange;
        }
        return res;
    }
};
