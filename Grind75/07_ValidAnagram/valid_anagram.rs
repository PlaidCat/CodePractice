/* https://leetcode.com/problems/valid-anagram
*
* Code Time:  23:39m (all Rust Lang Issues)
*  Run Time:     1ms (88.03%)
*    Memory:  2.30MB (35.42%)
* 
* Ran into Rust's inability to cast ints in place as normal numvers.
*/

impl Solution {
  pub fn is_anagram(s: String, t: String) -> bool {
      let mut chars: [i32; 26] = [0; 26];
      let s_bytes = s.into_bytes();
      let t_bytes = t.into_bytes();
      let mut i: usize = 0;
      while (i < s_bytes.len()){
          let index = (s_bytes[i] as usize) - (97 as usize);
          chars[index] += 1;
          i += 1;
      }
      i = 0;
      while (i < t_bytes.len()){
          let index = (t_bytes[i] as usize) - (97 as usize);
          chars[index] -= 1;
          i += 1;
      }
      i = 0;
      while (i < 26){
          if (chars[i] != 0){
              return false;
          }
          i += 1;
      }
      return true;
  }
}