/*
 * https://leetcode.com/problems/valid-parentheses
 * 
 * Code Time: 11:23 (I was trying to use a Rust Vec like a C++ Vector and Vec has less acessors)
 *  Run Time:   1ms (73.16%)
 *    Memory: 2.1MB (40.41%)
 * 
 */

impl Solution {
  pub fn is_valid(s: String) -> bool {
      let mut stack = Vec::new();
      for i in s.chars(){
          if (i == '(' || i == '{' || i == '['){
              stack.push(i);
          } else if (stack.len() > 0){
              let back = stack.len()-1;
              if (i == ')' && stack[back] == '('){
                  stack.pop();
              }else if ( i == '}' && stack[back] == '{'){
                  stack.pop();
              }else if ( i == ']' && stack[back] == '['){
                  stack.pop();
              }else{
                  return false;
              }
          } else {
              return false;
          }
      }
      if (stack.len() > 0){
          return false;
      }
      return true;
  }
}