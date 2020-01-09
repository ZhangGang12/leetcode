/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int a = 0, b = 0;
        int c = matrix.size() - 1, d = matrix[0].size() - 1;
        vector<int> res;
        int i, j;
        while(a <= c && b <= d){
            i = a;
            j = b;
            if(a == c){
                while(j <= d){
                res.push_back(matrix[i][j]);
                ++j;
                }
            }else if(b == d){
                while(i <= c){
                res.push_back(matrix[i][j]);
                ++i;
                }
            }else{
                while(i == a && j < d){
                    res.push_back(matrix[i][j]);
                    ++j;
                }
                while(j == d && c > i){
                    res.push_back(matrix[i][j]);
                    ++i;
                }
                while(i == c && j > b){
                    res.push_back(matrix[i][j]);
                    --j;
                }
                while(j == b && i > a){
                    res.push_back(matrix[i][j]);
                    --i;
                }
            }
            ++a;
            ++b;
            --c;
            --d;
        }
        return res;
    }
};
// @lc code=end

