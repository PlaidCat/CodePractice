/*
 * https://leetcode.com/problems/valid-palindrome/submissions
 * 
 * Code Time:  15:32
 *  Run Time:    0ms (100%)
 *    Memory: 2.23MB (76.33%)
 * 
 * This was interesting to learn about the String encoding aspect of RUST.
 * I jumped in like I did will all more taditional languages and was a little
 * surprised about the compiler errors on not being able to index strings.
 * Thankfully since the input was ensured to be ASCII I could convert it to
 * a btye array and do normal ugly things.  I also ran into the difference of
 * make_ascii_lowercase vs to_ascii_lowercase which I used make initiall but
 * since I kept the array immutable the compiler caught me and threw an error
 * protecting me from myself.  Neat.
 */

impl Solution {
  pub fn is_palindrome(s: String) -> bool {
      let bytes = s.into_bytes();
      if (bytes.len() < 2) {
          return true;
      }
      let mut start = 0;
      let mut end = bytes.len() - 1;

      while (start < end) {
          if ( ! bytes[start].is_ascii_alphanumeric() ){
              start += 1;
              continue;
          }
          if ( ! bytes[end].is_ascii_alphanumeric() ){
              end -= 1;
              continue;
          }
          if (bytes[start].to_ascii_lowercase() != bytes[end].to_ascii_lowercase()){
              return false;
          }
          start += 1;
          end -= 1;
      }
      return true;
  }
}