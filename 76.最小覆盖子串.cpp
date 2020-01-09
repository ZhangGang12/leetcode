/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;

        unordered_map<char,int> window;
        unordered_map<char,int> need;
        for(char c : t)need[c]++;
        int match = 0;
        while(right < s.size()){
            char c1 = s[right];
            //哈希表查找key是否存在用.count()
            if(need.count(c1)){
                window[c1]++;
                if(window[c1] == need[c1])match++;
            }
            right++;
            
            while(match == need.size()){
                if(right - left < minLen){
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if(need.count(c2)){
                    window[c2]--; //移除c2
                    if(window[c2] < need[c2])
                    match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};
// @lc code=end

