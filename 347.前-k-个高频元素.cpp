/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int,int>> map1;
        int i = 1;
        for(auto num : nums) {
            if(map[num] > 0) map1[map[num] - 1].second++;
            else{
                pair<int,int> tmp(num,1);
                map1.push_back(tmp);
                map[num] = i;
                i++;
            }
        }
        //比较器 c++ lambda
        // first < second true 升序 first > seconde true 降序
        sort(map1.begin(),map1.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.second > b.second) return true;
            return false;
        });
        vector<int> res;
        for(int j = 0; j < k; j++){
            res.push_back(map1[j].first);
        }
        return res;
    }
};
// @lc code=end

