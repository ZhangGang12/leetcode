/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //哈希表
        unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); ++i){
            if(map[target - nums[i]]){
                return {map[target - nums[i]] - 1,i};
            }else{
                map[nums[i]] = i+1;
            }
        }
        return {};
        
    }
};
// @lc code=end
/***暴力遍历
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
       ***/
 /***哈希表
        unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); ++i){
            if(map[target - nums[i]]){
                return {map[target - nums[i]] - 1,i};
            }else{
                map[nums[i]] = i+1;
            }
        }
        return {};
 ***/

