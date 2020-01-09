/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        //暴力法肯定是没有意义的
        //一般使用分而治之
        int l = 0, r = nums.size() - 1;
        if(nums.size() == 1) return nums[0];
        while(l <= r){
            int mid = l + (r - l)/2;
            if((mid == 0 && nums[mid] < nums[mid + 1]) || (mid == nums.size() - 1 && nums.size() - 1))
        }
    }
};
// @lc code=end

