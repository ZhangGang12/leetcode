/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //解题思路：求nums的总和，将总和除以2，写一个helper函数
        //转化为背包问题
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
        }
        if(sum%2 == 1) return false;
        return helper(nums,sum >> 1);
    }
    bool helper(vector<int>& nums,int target){
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,false));
        dp[0][0] =true;
        for(int i = 1; i <= nums.size(); ++i){
            dp[i] = dp[i-1];
            for(int j = target; j >= nums[i-1]; --j){
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
            if(dp[i][target]) return true;
        }
        return false;

    }
};
// @lc code=end

