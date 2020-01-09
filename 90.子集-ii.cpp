/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
         vector<int> temp;
        getAns(nums, 0, temp, res);
        return res;
    }

    void getAns(vector<int>& nums,int start,vector<int> temp,vector<vector<int>>& res){
        res.push_back(temp);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            getAns(nums,i + 1,temp, res);
            temp.pop_back();
        }
    }
};
// @lc code=end

