/*
 * https://leetcode.com/problems/two-sum
 * Doing very C / Kernel stuff here.
 * 
 * Runtime 386ms  (37.84%)
 * Memory  10.3MB (66.73%)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> ret(2, -1);
        for (i = 0; i < nums.size()-1; ++i){
            for (j = i+1; j < nums.size(); ++j){
                if ((nums[i]+nums[j]) == target)
                    goto exit;
            }
        }
exit:
        ret[0] = i;
        ret[1] = j;
        return ret;
    }
};