/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) ++i;
            if( i == path.size()) break;
            int start = i;
            while(path[i])
        }
    }
};
// @lc code=end

