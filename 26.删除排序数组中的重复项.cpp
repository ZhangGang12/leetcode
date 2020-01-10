/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针
        int len = nums.size();
        if(len == 0) return 0;
        int fast;
        int slow = 1;
        for(fast = 1; fast < len; ++fast){
            if(nums[fast] == nums[fast-1]){
                continue;
            }
            nums[slow] = nums[fast];
            ++slow;
        }
        return slow;
    }
};
// @lc code=end
/*双指针
    int len = nums.size();
    if(len == 0) return 0;
    int fast;
    int slow = 1;
    for(fast = 1; fast < len; ++fast){
        if(nums[fast] == nums[fast-1]){
            continue;
        }
        nums[slow] = nums[fast];
        ++slow;
    }
    return slow;
 */
