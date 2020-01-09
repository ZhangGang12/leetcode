/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2)));
        for(int i = 0; i < n; i++){
           if(0 == i){
               dp[i][2][0] = 0;
               dp[i][2][1] = -prices[i];
               dp[i][1][0] = 0;
               dp[i][1][1] = -prices[i];
               continue;
           }
           dp[i][1][1] = max(dp[i-1][1][1],-prices[i]);
           dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][1][1] + prices[i]);
           dp[i][2][1] = max(dp[i-1][2][1],dp[i-1][1][0] - prices[i]);
           dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][2][1] + prices[i]);
        }
        return dp[n-1][2][0];
    }
};
// @lc code=end

/*
 *多维度vector初始化
 *二维：vector<vector<int>> res;
 *2x3：vector<vector<int>> res(2,vector<int>(3));
 */
/*
 *  int maxProfit(vector<int>& prices) {
 *       int n = prices.size();
 *       if(n == 0)return 0;
 *       vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2)));
 *       for(int i = 0; i < n; i++){
 *          if(0 == i){
 *              dp[i][2][0] = 0;
 *              dp[i][2][1] = -prices[i];
 *              dp[i][1][0] = 0;
 *              dp[i][1][1] = -prices[i];
 *              continue;
 *          }
 *          //
 *          dp[i][1][1] = max(dp[i-1][1][1],-prices[i]);
 *          dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][1][1] + prices[i]);
 *          dp[i][2][1] = max(dp[i-1][2][1],dp[i-1][1][0] - prices[i]);
 *          dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][2][1] + prices[i]);
 *       }
 *       return dp[n-1][2][0];
 V   }
 */