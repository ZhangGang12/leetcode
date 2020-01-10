/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0;
        while(left < len){
            if(nums[left] == val){
                nums[left] = nums[len-1];
                --len;
            }else{
                ++left;
            }  
        }
        return left;
    }
};
// @lc code=end
/* 双指针 
 * 当 nums[i] 与给定的值相等时，递增 i 以跳过该元素。
 * 若不等则将i赋值给left并两个都递增
 * int len = nums.size();
 * int left = 0;
 * for(int i = 0; i < len; ++i){
 *    if(nums[i] == val) continue;
 *       nums[left] = nums[i];
 *       ++left;
 *   }
 * return left;
 */
/* 双指针 
 * 当 nums[left] 与给定的值相等时，将left与最后的值交换。
 * 并减少len的值，释放最后一个数
 * int len = nums.size();
 * int left = 0;
 * while(left < len){
 *     if(nums[left] == val){
 *       nums[left] = nums[len-1];
 *       --len;
 *     }else{
 *       ++left;
 *      }  
 * }
 * return left;
 */

