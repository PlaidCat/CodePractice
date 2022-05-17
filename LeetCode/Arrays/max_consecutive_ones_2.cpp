
/*
 * 
 * https://leetcode.com/problems/max-consecutive-ones-ii
 * 
 * Runtime: 64 ms (27.46% Better)
 * Memory Usage: 36.78 MB (36.78% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 * 
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int count = 0;
      int count_zero = 0;
      int penulitmate = 0;
      int max=0;
      for (int i = 0; i < nums.size(); ++i){
        if (nums[i]==0){
          //printf("nums[%i] num 1's to left = %i\tpenulitmate=%i\tmax=%i\n", i, count,penulitmate,max);
          if ((count + penulitmate) > max){
            max =(count + penulitmate);
          }
          count_zero = 1;
          penulitmate = count;
          count = 0;
        } else{
          count++;
        }
      }
      //printf("nums[%i] num 1's to left = %i\tpenulitmate=%i\tmax=%i\n", nums.size()-1, count,penulitmate,max);
      if ((count + penulitmate) > max){
            max =(count + penulitmate);
      }
      return max+count_zero;
    }
};