/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //排序
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])return true;
        }
        return false;
    }
};
// @lc code=end
/* 使用哈希表
    bool containsDuplicate(vector<int>& nums) {
        //使用map
        unordered_map<int,int>map;
        for(int i = 0; i < nums.size(); ++i){
            if(map[nums[i]] > 0)return true;
            map[nums[i]]++;
        }
        return false;
    }
 */
/*
//排序
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1])return true;
        }
        return false;
*/
