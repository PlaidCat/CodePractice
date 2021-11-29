/*
 * Write a function that reverses a string. The input string is given as an array of characters s.0
 *
 * You must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * https://leetcode.com/problems/reverse-string/
 * Runtime: 40 ms  (98.80% Better)
 * Memory Usage: 12.5 MB (25.18% better)
 */

void reverseString(char* s, int sSize){
  int front = 0;
  int back = sSize -1;
  char swap;
  while (front < back){
    swap = s[front];
    s[front] = s[back];
    s[back] = swap;
    front++;
    back--;
  }
}