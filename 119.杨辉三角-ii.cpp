/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //公式法：
        vector<int> res(rowIndex + 1,1);
        for(int k = 1; k < rowIndex; ++k){
            long cur = res[k - 1];
            res[k] = (int)(cur * (rowIndex - k + 1)/k);
        }
        return res;
    }
};
// @lc code=end

/* 与上题一样的思路，时间复杂度较高，为O(n2)
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1,1);
        if(rowIndex == 0) return res;
        //思路和上面一样
        for(int i = 0; i < rowIndex; ++i){
            int temp;
            int temp1 = 1;
            for(int j = 1; j <= i; ++j){
                temp = res[j];
                res[j] = res[j] + temp1;
                temp1 = temp;
            }
        }
        return res;
    }
 * 优化：顺着加改为倒着加，取消了两个中间存储变量
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1,1);
        if(rowIndex == 0) return res;
        //思路和上面一样
        for(int i = 0; i < rowIndex; ++i){
            for(int j = i; j >= 1; --j){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
*/