# https://leetcode.com/problems/best-time-to-buy-and-sell-stock
#  
# Code:   3:38 - This is all typing time and some mixing up profit and prices
#  CPU:  806ms (97.28%)
#  MEM: 27.4MB (21.26%)
# This is a very C way to write this and is more of a practice
# I'm also SHOCKED that 806ms is beating 97.28% of submissoins and that its
# just so slow
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit: int = 0
        price_min: int = -1

        price_min = prices[0]

        for i in range(1, len(prices)):
            if prices[i] < price_min:
                price_min = prices[i]
            elif ((prices[i] - price_min) > profit):
                profit = (prices[i] - price_min)

        return profit