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
        int total = 0, sum = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0){
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
};
// @lc code=end
/*
 *如果一个数组的总和非负，那么一定可以找到一个起始位置，从他开始绕数组一圈，累加和一直都是非负的
 *1. 假如从位置i开始，i+1，i+2...，一路开过来一路油箱都没有空。说明什么？说明从i到i+1，i+2，...肯定是正积累。
 *2. 现在突然发现开往位置j时油箱空了。这说明什么？说明从位置i开始没法走完全程(废话)。
 *   那么，我们要从位置i+1开始重新尝试吗？不需要！为什么？因为前面已经知道，位置i肯定是正积累，
 *   那么，如果从位置i+1开始走更加没法走完全程了，因为没有位置i的正积累了。同理，也不用从i+2，i+3，...开始尝试。
 *   所以我们可以放心地从位置j+1开始尝试。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0){
                start = i + 1;
                sum = 0;
            }
        }
        return (total < 0) ? -1 : start;
    }
 */


/* 数组头尾组成链循环可以用%取余的方法进行循环
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for(int i = 0; i < len; ++i){
            int cur = i;
            int remind = 0; //第一个cur绝对在0~len-1之中所以不用担心
            for(int j = 0; j < len; ++j){
                remind += gas[cur];
                remind -= cost[cur];
                ++cur;
                cur = cur%len; //利用取余法进行循环
                if(remind < 0)break;
                if(cur == i) return cur;
            }
        }
        return -1;
    }
*/

