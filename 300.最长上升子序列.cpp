/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i = 1; i<nums.size();i++){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1,dp[i]);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < dp.size(); i++){
            if(res < dp[i]) res = dp[i];
        }
        return res;
    }
};
// @lc code=end

