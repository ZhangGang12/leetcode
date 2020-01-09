/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return "";
        int k = 0;
        int len = s.length();
        while(k < len && s[k] == ' ') k++;
        if(len == k) return "";
        stack<string> st;
        string res = "";
        while(k < len){
            string temp = "";
            while(k < len && s[k] != ' '){
                temp += s[k];
                ++k;
            }
            if(temp.size() > 0)
            st.push(temp);
            k++;
        }
        res += st.top();
        st.pop();
        while(!st.empty()){
            res += ' ';
            res += st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end

