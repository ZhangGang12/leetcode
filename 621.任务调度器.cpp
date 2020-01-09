/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //暴力调度
        //以n为基准，mei
       vector<int> map(26);
       for(int i = 0; i < tasks.size(); i++){
           map[tasks[i] - 'A']++;
       }
       sort(map.begin(),map.end());
       int time = 0;
       while(map[25] > 0){
           int i = 0;
           while(i <= n){ //每次循环执行n个
               if(map[25] == 0) break;
               if(i < 26 && map[25-i] > 0) map[25-i]--;
               time++;
               i++;
           }
           sort(map.begin(),map.end());
       }
       return time;
    }
};
// @lc code=end

