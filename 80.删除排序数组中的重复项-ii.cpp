/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int count = 1;
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(count < 2){
                    nums[k] = nums[i];
                    count++;
                    k++;
                }
            }
            else{
                count = 1;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
// @lc code=end

