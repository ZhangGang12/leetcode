/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]) i += 2;
            else return nums[i];
        }
        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums.back();
        return 0;
    }
};
// @lc code=end

