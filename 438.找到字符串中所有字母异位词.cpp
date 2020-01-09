/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        if(lens < lenp) return {};

        unordered_map<char,int> needs;
        unordered_map<char,int> window;
        for(char c : p) needs[c]++;

        vector<int> res;
        int match = 0;
        int left = 0;
        while(left < lens){
            if(left >= lenp){
                //need此时s[left-lenp]有其他不同的参数
                //会让need增加key但是key对应的value值为0
                if(window[s[left-lenp]] <= needs[s[left-lenp]])match--;
                window[s[left-lenp]]--;
                }
            char c1 = s[left];
            left++;
            window[c1]++;
            if(needs[c1] >= window[c1])match++;
            if(match == lenp) res.push_back(left-lenp);  
        }
        return res;
    }
};
// @lc code=end

