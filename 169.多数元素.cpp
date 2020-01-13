/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore投票算法（自行百度）
        int count = 0;
        int temp;
        for(auto num : nums){
            if(count == 0) temp = num;
            count += (num == temp) ? 1 : -1;
        }
        return temp;
        
    }
};
// @lc code=end
/*
    int majorityElement(vector<int>& nums) {
        //哈希表 
        int len = nums.size();
        unordered_map<int,int> map;
        for(int i = 0; i < len; ++i){
            map[nums[i]]++;
            if(map[nums[i]] > len/2 ) return nums[i];
        }
        return 0;
    }
 */
/*
 * 排序
 * 0 1 2 3 4 5 6 //基数7 ， 7/2 = 3， 下标为3
 * 0 1 2 3 4 5   //偶数6 ， 6/2 = 3， 下标为3
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
 */
/*
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore投票算法（自行百度）
        int count = 0;
        int temp;
        for(auto num : nums){
            if(count == 0) temp = num;
            count += (num == temp) ? 1 : -1;
        }
        return temp;
        
    }
 */
