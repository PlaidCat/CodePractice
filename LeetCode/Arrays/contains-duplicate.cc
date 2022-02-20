/*
 * I did this in C++ beacuse I really didn't want to write a sorting algo in C
 * I did attempt to do a Range bucket in C with Shorts as the datatype over
 * the range of possible number in a signed int but leet code didn't want a 
 * huge array like that :P  I agree its not super space complexity efficient.
 *
 * https://leetcode.com/problems/contains-duplicate/
 * 
 * Runtime: 113 ms (62.93% Better)
 * Memory Usage: 46.7 MB (75.10% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      for (int i =0; i < nums.size()-1; ++i){
        if (nums[i] == nums[i+1])
          return true;
      }
      return false;
    }
};