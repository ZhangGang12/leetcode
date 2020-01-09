/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        const int n = prices.size();
        int dp[n][2];
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0],dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i] );
            //由上可知i永远由i-1推导而来
            //所以将dp[][]数组使用dp0，dp1代替减少复杂度
        }
        return dp[n-1][0];
    }
};
// @lc code=end
 /*
  *int minprice = INT_MAX;
  *       int maxprice = 0; 
  *      for(int i = 0; i < prices.size(); i++){
  *          if(prices[i] < minprice){
  *              minprice = prices[i];
  *          }else if(prices[i] - minprice > maxprice) 
  *          maxprice = prices[i] - minprice;
  *      }
  *      return maxprice;
  */

/*
 *  if(prices.size() <= 1) return 0;
 *     int dp;
 *     dp = max(0,prices[1] - prices[0]);
 *     int profit = dp;
 *     for (int i = 1; i < prices.size() - 1; i++){
 *     dp = max(0, dp + prices[i+1] - prices[i]);
 *     profit = max(profit,dp);
 *     }
 *    return profit;
 */