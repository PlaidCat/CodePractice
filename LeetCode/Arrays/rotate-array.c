/*
 * I've been stuck on this problem for the past couple of times I tried.
 * I was contistently having an issue with moving the elements with a single
 * swap element to meet the O(1) by moving the elements based on k progress.
 * However I had to read the solution to remember that O(1) memory is just
 * fixed regarless of the size of N, as long is not O(N) or O(k).
 *
 * https://leetcode.com/problems/rotate-array/
 * 
 * Runtime: 141 ms (62.91% Better)
 * Memory Usage: 22.2 MB (58.87 Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 */

void print_array(int*nums, int numsSize){
  int i = 0;
  for (i ; i < numsSize; ++i){
    printf("%i,", nums[i]);
  }
  printf("\n");
}


void rotate(int* nums, int numsSize, int k){
  int i = 0;
  int j = 0;
  int p = 0;
  int count = 0;
  int swap = 0;
  k %= numsSize;

  
  for (i = 0; count < numsSize; ++i){
    int cur = i;

    swap = nums[cur];
    do {
      int next = (cur + k) % numsSize;
      int tmp = nums[next];
      //printf("i: %i =?= ", i);
      //printf("cur: %i\n", cur);
      //printf("next: %i\n", next);
      //printf("swap: %i\n", swap);
      //printf("tmp: %i\n", tmp);
      nums[next] = swap;
      swap = tmp;
      cur = next;
      //printf("cur: %i\n", cur);
      count++;
    }while (cur != i);
    //print_array(nums, numsSize);
  }
}