/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H指数
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //计数排序
        int len = citations.size();
        vector<int> map(len+1,0);
        for(int i = 0; i < len; ++i){
            if(citations[i] > len )map[len]++;
            else map[citations[i]]++;
        }
        int sum = 0;
        for(int i = len; i >0; i--){
            sum += map[i];
            if(sum >= i) return i;
        }
        return 0;   
    }
};
// @lc code=end
/*
    int hIndex(vector<int>& citations) {
        //排序
        sort(citations.begin(),citations.end());
        int i = 0;
        while(i < citations.size() && citations[citations.size() - 1 - i] > i){
            ++i;
        }
        return i;
    }
*/
/* 桶排序
    int hIndex(vector<int>& citations) {
        //计数排序
        int len = citations.size();
        vector<int> map(len+1,0);
        for(int i = 0; i < len; ++i){
            if(citations[i] > len )map[len]++;
            else map[citations[i]]++;
        }
        int sum = 0;
        for(int i = len; i >0; i--){
            sum += map[i];
            if(sum >= i) return i;
        }
        return 0;   
    }
*/

