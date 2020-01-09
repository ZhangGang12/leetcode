/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        helper(s,temp,res,0);
    }

    void helper(string& s,vector<string> temp, vector<vector<string>>& res,int cur){
        //判断是否是回文串
        if(!temp.empty()){
            string b = temp.back();
            int last = b.size() - 1;
            int start = 0;
            while(start <= last){
                if(b[start] != b[last]) return;
                ++start;
                --last;
            }
        }

        if( cur == s.size()) res.push_back(temp);
        string a = "";
        for(int i = cur; cur < s.size(); i++){
            a += s[i];
            temp.push_back(a);
            helper(s,temp,res,cur + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end

