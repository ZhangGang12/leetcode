/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        return dfs(-1,s);

    }
    int dfs(int start, string& s){
        if(start == s.size() - 1) return 1;
        if(s[start+1] == '0') return 0;
        int one = dfs(start+1,s);
        int two = 0;
        if(start+2 < s.size()){
            int a = s[start+1] - '0';
            a = a*10 + s[start+2] - '0';
            if(a <= 26) two = dfs(start + 2,s);
        }
        return one + two;
    }
};
// @lc code=end

