/*
 * 88. Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/
 * 
 * Runtime: 4 ms (81.69% Better)
 * Memory Usage: 6.2 MB (55.21% Better)
 * 
 */
#include <stdlib.h>
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
  int back = nums1Size -1;
  int i = m - 1;
  int j = n - 1;
  while ((i >= 0) && (j >= 0)){
    if (nums1[i] >= nums2[j]){
      nums1[back] = nums1[i];
      i--;
    } else {
      nums1[back] = nums2[j];
      j--;
    }
    back--;
  }
  for(i; i>=0; i--){
    nums1[back] = nums1[i];
    back--;
  }
  for(j; j>0; j--){
    nums1[back] = nums2[j];
    back--;
  }
}