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
        //哈希表配合滑动窗口
        unordered_map<int,int> map;
        if(nums.size() < k) k = nums.size();
        for(int i = 0; i < k; i++){
            if(map[nums[i]] > 0)return true;
            map[nums[i]]++;
        }
        for(int i = k; i < nums.size(); i++){
            if(map[nums[i]] > 0)return true;
            map[nums[i]]++;
            map[nums[i-k]] = 0;
        }
        return false;
    }
};
// @lc code=end
/*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //哈希表配合滑动窗口
        unordered_map<int,int> map;
        if(nums.size() < k) k = nums.size();
        for(int i = 0; i < k; i++){
            if(map[nums[i]] > 0)return true;
            map[nums[i]]++;
        }
        for(int i = k; i < nums.size(); i++){
            if(map[nums[i]] > 0)return true;
            map[nums[i]]++;
            map[nums[i-k]] = 0;
        }
        return false;
    }
 */
