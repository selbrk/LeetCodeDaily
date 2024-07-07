class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, ans = 0;
        while (numBottles) {
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;
            numBottles += empty / numExchange;
            empty = empty % numExchange;
        }
        return ans;




    }
};