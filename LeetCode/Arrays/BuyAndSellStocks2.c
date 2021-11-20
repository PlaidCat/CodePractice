/*
 * Since you can buy and sell on each and every itteration you do not need
 * to do anything complex just, if the current day is more record the diff
 * and thats the profit to add in.
 *
 *  https://leetcode.com/PlaidCat/
 */

int maxProfit(int* prices, int pricesSize){
  int i;
  int profit = 0;
  if (pricesSize <= 1)
    return 0;
  for (i = 1; i < pricesSize; ++i){
    if (prices[i-1] < prices[i])
      profit += (prices[i] - prices[i-1]);
  }
  return profit;
}
