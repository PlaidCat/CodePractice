/*
 * Based this off the basic C program in the same dir.
 * 
 * A lot of this was trying to take something that is very easy for me to understand
 * and put it into the voodoo of the rust compiler.
 *
 * https://leetcode.com/problems/rotate-array/
 * 
 * Runtime: 20 ms (29.68% Better)
 * Memory Usage: 3.6 MB (87.70 Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 */

impl Solution {
  pub fn rotate(nums: &mut Vec<i32>, k: i32) {
    let len = (nums.len());
    let my_k = ((k as usize) % len);
    let mut count = 0;
    let mut i: usize = 0;
    
    while count < nums.len() {
      let mut cur: usize = i;
      //println!("nums[{}] = {}", cur, nums[cur]);
      let mut swap = nums[cur];
      loop {
        let next: usize = (cur + my_k) % len;
        let tmp = nums[next];
        //println!("Cur: {} -> Next: {} == k: {}\n", cur, next, my_k);
        nums[next] = swap;
        swap = tmp;
        cur = next;
        count += 1;
        if cur == i { break; }
      } 
      i+=1;
    }
  }
}