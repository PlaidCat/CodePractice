/*
 * Rustification of C++ code.
 * I'm finding it weird that I have to make a mutative copy to do this,
 * it might be just as easy to build a hash map rather than using the extra
 * memory right off the bat.
 *
 * https://leetcode.com/problems/contains-duplicate/
 * 
 * Runtime: 20 ms (53.85% Better)
 * Memory Usage: 3 MB (66.43% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 */

impl Solution {
  pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut my_nums: Vec<i32> = nums;
    my_nums.sort();
    for i in 0..(my_nums.len()-1) {
      if my_nums[i] == my_nums[i+1] {
        return true;
      }
    }
    return false;
  }
}