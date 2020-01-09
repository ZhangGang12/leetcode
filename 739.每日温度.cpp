/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
       //暴力法
       vector<int> res; 
       for(int i = 0 ; i < T.size() - 1; i++){
           bool flage = false;
           for(int j = i + 1; j < T.size(); j++){
               if(T[j] > T[i]) {
                   res.push_back(j-i);
                   flage = true;
                   break;
                   }
           }
           if(!flage) res.push_back(0);
       }
       res.push_back(0);
       return res;
    }
};
// @lc code=end

