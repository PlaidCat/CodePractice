/**
 * https://leetcode.com/problems/two-sum/
 * Runtime: 153ms (29.80%)
 * Memory: 6.2MB (99.24%)
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int)*2);
    *returnSize = 2;
    int i, j;
    for (i = 0; i < numsSize-1; ++i){
        for (j = i+1; j < numsSize; ++j){
            if (nums[i]+nums[j] == target){
                ret[0] = i;
                ret[1] = j;
                printf("ret[0]=%d ret[1]=%d", ret[0], ret[1]);
                //*returnSize = 2;
                return ret;
            }
        }
    }
    return ret;
}
