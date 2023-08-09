/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *  
 * Code:  10:17  - BORROW CHECKER!!
 *  CPU:   13ms (71.82%)
 *  MEM: 2.85MB (93.95%)
 * This took a minute of reading docs to use a more normal iterator rather
 * than doing what I did in the python version of using the range of 
 * (1..len(prices)).  I figured there was a way to start in further into the
 * vector and it turns out to have two ways.
 * 1. The way impelemented below
 * 2. Using a slice before the iter.
 *    price in prices[1..v].iter()
 * I wasn't sure how the preformance (I know not something I should think about)
 * in this type of challenge but GradSchool and HPC got to me.
 * 
 * However for 3 relatively similar programs I was really impressed with
 * the Runtime and Memory usage of Rust compaired to even C/C++
 */

impl Solution {
  pub fn max_profit(prices: Vec<i32>) -> i32 {
      let mut profit: i32 = 0;
      let mut min: i32 = 0;

      min = prices[0];

      for price in prices.iter().skip(1) {
          if (min > *price) {
              min = *price;
          } else if ((*price - min) > profit) {
              profit = (*price - min);
          }
      }

      return profit;
  }
}