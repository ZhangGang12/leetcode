/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp0 = 0, dp1 = INT_MIN + fee;
        for(int i = 0; i < n; i++){
            int temp = dp0;
            dp0 = max(dp0,dp1 + prices[i] - fee);
            dp1 = max(dp1,temp - prices[i]);
        }
        return dp0;
    }
};
// @lc code=end

