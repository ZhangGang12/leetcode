/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> type;
        for (int i = 1; i <= n; ++i){
            int mul = i*i;
            if(mul > n) break;
            type.push_back(mul);
        }
        vector<int> dp(n+1,0);
        for(int i = 1; i <= n; ++i){
            int min_n = INT_MAX;
            for(int value : type){
                if(i - value < 0)break;
                min_n = min(min_n, dp[i-value] + 1);
            }
            dp[i] = min_n;
        }
        return dp[n];
    }
};
// @lc code=end

