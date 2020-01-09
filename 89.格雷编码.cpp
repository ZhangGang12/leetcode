/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int G = 1;
        int k = 1;
        int temp = 1;
        res.push_back(0);
        while( k <= n){
            for(int i = G - 1; i >= 0; i--){
                res.push_back(res[i] + temp);
            }
            G = G + G;
            ++k;
            temp = temp << 1;
        }
        return res;
    }
};
// @lc code=end

