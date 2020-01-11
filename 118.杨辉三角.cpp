/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 0) return res;
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j <= i; ++j){
                if(j == 0 || j == i){
                    res[i].push_back(1);
                }else{
                    res[i].push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
/* 虽然此题简单，但是根据题目写好逻辑代码仍然不易
 *  核心逻辑：
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 0) return res;
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j <= i; ++j){
                if(j == 0 || j == i){
                    res[i].push_back(1);
                }else{
                    res[i].push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
        }
        return res;
    }
 */
