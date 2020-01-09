/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        vector<vector<long long>> map(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size()));
        //遍历第零行和列
        for(int i = 0; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1){
                while(i < obstacleGrid.size()){
                    map[i][0] == 0;
                    i++;
                }
            }else{
                map[i][0] = 1;
            }
        }
        for(int j = 1; j < obstacleGrid[0].size(); j++){
            if(obstacleGrid[0][j] == 1){
                while(j < obstacleGrid[0].size()){
                    map[0][j] == 0;
                    j++;
                }
            }else{
                map[0][j] = 1;
            }
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1){
                    map[i][j] = 0;
                }else{
                    map[i][j] = map[i-1][j] + map[i][j-1];
                }
            }
        }
        return map[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        
    }
};
// @lc code=end

