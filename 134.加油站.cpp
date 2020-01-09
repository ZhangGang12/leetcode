/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        bool a , b;
        for(int i = 0; i < gas.size(); i++){
            int oil = 0;
            int cur;
            for(int j = 0; j < gas.size(); j++){
                cur = j + i;
                
                if(cur >= gas.size()) cur -= gas.size();
                oil += gas[cur];
                oil -= cost[cur];
                if(oil < 0)break;
                if(j == gas.size() - 1) return i;   
            }
        }
        return -1;
    }
};
// @lc code=end

