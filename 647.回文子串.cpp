/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = 0;
        for(int i = 1; i < len*2; i++){
            int count = 0;
            if(i%2){
                int j = i/2;
                count++;
                for(int k = 1; j - k >= 0 && j + k < len; k++){
                    if(s[j - k] == s[j + k]) count++;
                    else break;
                }
            }else{
                for(int j = 1; i - j >= 0 && i + j <= len*2; j += 2){
                    if(s[(i - j)/2] == s[(i + j)/2]) count++;
                    else break;
                }
            }
            res += count;
        }
        return res;
    }
};
// @lc code=end

