/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string &s, int count, int start){
        int len = s.length();
        vector<string> res;
        for(int i = start; i < start + 3; i++){ //count 表示剩余几个
            if(count == 0 && i != len - 1) continue;
            if((len - i - 1) > (count * 3)) continue;
            if((len - i - 1) < (count * 1)) continue;

            string sub = s.substr(start, i - start + 1);
            int ip = stoi(sub);
            if(ip < 0 || ip > 255) continue;
            if(to_string(ip) != sub) break;

            if(count == 0){
                res.push_back(sub);
            }

            vector<string> vs = restoreIpAddresses(s,count - 1, i + 1);
            for(auto &v : vs){
                res.push_back(sub + "." + v);
            }
            
        }
        return res;
    }

    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s,3,0);
    }
};
// @lc code=end

