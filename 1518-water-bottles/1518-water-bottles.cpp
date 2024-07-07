class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, qt = 0;
        while(numBottles >= numExchange) {
            qt = numBottles / numExchange;
            numBottles = qt + (numBottles % numExchange);
            res += qt;
        }
        return res;
    }
};