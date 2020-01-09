/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int c1 = 0, c2 = 0;
        while(c1 < len1 || c2 < len2){
            int num1 = 0, num2 = 0;
            while(c1 < len1 && version1[c1] != '.' ){
                num1 = num1*10 + version1[c1] - '0';
                ++c1;
            }
            while(c2 < len2 && version2[c2] != '.' ){
                num2 = num2*10 + version2[c2] - '0';
                ++c2;
            }
            ++c1;
            ++c2;
            if(num1 == num2)continue;
            if(num1 > num2) return 1;
            else return -1;
        }
        return 0;
    }
};
// @lc code=end

