/*
 * https://leetcode.com/problems/two-sum/
 * 
 * I was attempting to use the built in vector for loops.
 * 
 * RunTime  30ms (24.78%)
 * Memory  2.1MB (81.47%)
 */

impl Solution {
  pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
      let mut i = 0;
      let mut j = 0;
      while i < nums.len(){
          j = i + 1; 
          while j < nums.len(){
              if((nums[i]+nums[j]) == target){
                  return vec![i as i32, j as i32];
              }
              j+=1;
          }
          i+=1;
      }
      return vec![0,0];
  }
}