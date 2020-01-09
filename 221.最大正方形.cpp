/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        int maxval = 0;
        vector<vector<int>> dp(row+1,vector<int>(col+1));

        for(int i = 0; i <= row; ++i){
            for(int j = 0; j <= col; ++j){
                if (i == 0 || j == 0) dp[i][j] = 0;
                else {
                    if(matrix[i-1][j-1] == '1'){
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                        if(dp[i][j] > maxval){
                            maxval = dp[i][j];
                        }
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return maxval*maxval;
    }
};
// @lc code=end

