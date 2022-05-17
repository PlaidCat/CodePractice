/*
 * https://leetcode.com/problems/find-numbers-with-even-number-of-digits//
 * 
 * Runtime: 7 ms (72.67% Better)
 * Memory Usage: 9.8 MB (46.91% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int num_even = 0;
      for (int i = 0 ; i < nums.size(); ++i){
        int temp = nums[i];
        int digits = 1;
        while (temp /= 10)
          digits++;
        if (!(digits % 2))
          num_even++;
      }
      return num_even;
    }
};