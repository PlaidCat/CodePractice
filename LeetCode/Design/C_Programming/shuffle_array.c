/*
 * https://leetcode.com/problems/shuffle-an-array/
 * Medium
 * https://leetcode.com/submissions/detail/595281620/?from=explore&item_id=670
 * 
 * Runtime: 220 ms (75% Better than Other submissions)
 * Memory Usage: 35.9 MB (100% Better than other submissions, note its not putting my marker on the page an it seems to start at 36000KB)
 */ 

typedef struct {
  int* original;
  int* shuffle;
  int size;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
  Solution *obj = (Solution*)malloc(sizeof(Solution));
  obj->original = (int*)malloc(sizeof(int)*numsSize);
  obj->size = numsSize;
  obj->shuffle = (int*)malloc(sizeof(int)*numsSize);
  int i;
  memcpy(obj->original, nums, obj->size*(sizeof(int)));
  memcpy(obj->shuffle, nums, obj->size*(sizeof(int)));
  return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
  memcpy(obj->shuffle, obj->original, obj->size*(sizeof(int)));
  *retSize = obj->size;
  return obj->shuffle;
}

int* solutionShuffle(Solution* obj, int* retSize) {
  int i, swap, tmp;
  /*for (i=obj->size-1; i >0; --i){
    tmp = obj->shuffle[i];
    swap = rand() % obj->size;
    obj->shuffle[i] = obj->shuffle[swap];
    obj->shuffle[swap] = tmp;
  }
  */
  for (i=0; i < obj->size; ++i){
    tmp = obj->shuffle[i];
    swap = rand() % obj->size;
    obj->shuffle[i] = obj->shuffle[swap];
    obj->shuffle[swap] = tmp;
  }
  *retSize = obj->size;
  return obj->shuffle;
}

void solutionFree(Solution* obj) {
  free(obj->original);
  free(obj->shuffle);
  free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/