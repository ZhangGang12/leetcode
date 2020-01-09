/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int first = 0;
        int second ;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]) return i;
        }
        return nums.size() - 1;
    }
};
// @lc code=end

