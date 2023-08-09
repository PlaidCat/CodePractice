/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *  
 * Code:  I forgot to time but enought for my slow typing
 *  CPU:   102ms (81.91%)
 *  MEM: 13.19MB (10.86%)
 * With this one I always think its the local peaks and get myself worked up
 * This is the first time I'm like I'm going to do it dead simple first and
 * see where we get.
 */
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int min = 0;
    int i = 0;

    if (pricesSize < 2)
        return profit;
    
    min = prices[0];

    for (i = 1; i < pricesSize; ++i){
        if (min > prices[i]){
            min = prices[i];
        } else if ((prices[i] - min) > profit) {
            profit = (prices[i] - min);
        }
    }

    return profit;
}