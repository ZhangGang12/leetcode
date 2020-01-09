/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //创建固定大小的vector
        vector<vector<int>> res(n,vector<int>(n));
        int a = 0, b = 0;
        int c = n-1 , d = n - 1;
        int i,j;
        int temp = 1;
        while( a <= d && b <= d){
            i = a, j = b;
            if(a == d){
                res[i][j] = temp;
            }else{
                while( i == a && j < d){
                    res[i][j] = temp;
                    ++temp;
                    ++j;
                }
                while( j == d && i < c){
                    res[i][j] = temp;
                    ++temp;
                    ++i;
                }
                while( i == c && b < j){
                    res[i][j] = temp;
                    ++temp;
                    --j;
                }
                while( j == b && a < i){
                    res[i][j] = temp;
                    ++temp;
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

