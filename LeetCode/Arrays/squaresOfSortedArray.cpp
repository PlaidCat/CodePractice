
/*
 * I have some misses on this because I was trying to figure out how to
 * do the problem with O(n) runtime and O(1) space complexity by resuing
 * the elements of the array, but the full negative array threw me for a
 * failure case.
 * 
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 * 
 * Runtime: 36 ms (77.69% Better)
 * Memory Usage: 25.9 MB (55.57% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int left = 0;
      int right = nums.size() - 1;
      vector <int> ret(nums.size());
      for (int i = nums.size()-1; i >=0; --i){
        int sq = 0;
        if (abs(nums[right]) > abs(nums[left])){
          sq = nums[right];
          right--;
        } else {
          sq = nums[left];
          left++;
        }
        ret[i] = sq * sq;
      }
      return ret;
    }
};