/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        int n = prices.size();
        int dp0 = 0, dp1 = INT_MIN;
        int dp_pre = 0;
        for(int i = 0; i < n; i++){
            int temp = dp0;
            dp0 = max(dp0,dp1 + prices[i]);
            dp1 = max(dp1, dp_pre - prices[i]);
            dp_pre = temp;
        }
        return dp0;
    }
};
// @lc code=end

