/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *  
 * Code:    2:58 - This is all typing time and some mixing up profit and prices
 *  CPU:    96ms (90.25%)
 *  MEM: 93.31MB (10.86%)
 * I started with the C code one and realized as I was rewriting this that I
 * was trying to be overly branchy on exiting early if we know what the exit
 * conditions will be.  Since if the inpu value is 1 if you only assign
 * profit in the for loop you'll short circuit the for loop.  Saves on branch
 * prediction misses :D
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = -1;

        min = prices[0];
        for (int i = 1; i < prices.size(); ++i){
            if (min > prices[i]){
                min = prices[i];
            } else if ((prices[i] - min) > profit){
                profit = (prices[i] - min);
            }
        }
        
        return profit;    
    }
};