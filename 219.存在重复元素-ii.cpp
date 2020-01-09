/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //哈希表
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]] == 1) return true;
            map[nums[i]] = 1;
            if(i >= k )map[nums[i-k]] = 0;
        }
        return false;
    }
};
// @lc code=end

