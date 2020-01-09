/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        int len = prices.size();
        int dp0 = 0, dp1 = INT_MIN;
        for(int i = 0; i < len; i++){
            int temp = dp0;
            dp0 = max(dp0,dp1 + prices[i] );
            dp1 = max(dp1, temp - prices[i]);
        }
        return dp0;
    }
};
// @lc code=end
/*贪心算法
        if(prices.size() <= 1)return 0;
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++){
            if(prices[i+1] - prices[i] > 0) res += prices[i+1] - prices[i] ;
        }
        return res;
        */

