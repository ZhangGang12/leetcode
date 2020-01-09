/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
       /* 二分法 */
       if(nums.size() == 0) return false;
       int star = 0;
       int end = nums.size() - 1;
       int mid;
       while(star <= end){
           mid = star + (end - star)/2;
           if(nums[mid] == target){
               return true;
           }
           if(nums[star] == nums[mid]){
               star++;
               continue;
           }
           //前半部分有序
           if(nums[star] < nums[mid]){
               if(nums[star] <= target && target < nums[mid]){
                   end = mid - 1;
               }else{
                   star = mid + 1;
               }
           }else{
               //后半部分有序
               if(nums[mid] < target && target <= nums[end]){
                   star = mid + 1;
               }else{
                   end = mid - 1;
               }
           }
        }
        return false;
    }
};
// @lc code=end

/*无脑遍历法
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == target) return true;
            ++i;
        }
        return false;
*/