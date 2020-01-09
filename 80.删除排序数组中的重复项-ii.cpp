/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int cur = 1;
        for(int i = 2; i < len; ++i){
            if(nums[i] != nums[cur-1]){
                ++cur;
                nums[cur] = nums[i];
            }
        }
        return cur+1;
    }
};
// @lc code=end
/* 判断cur-1的值与i的值是否相等，如果不等表示i的值可以移动到cur处
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int cur = 1;
        for(int i = 2; i < len; ++i){
            if(nums[i] != nums[cur-1]){
                ++cur;
                nums[cur] = nums[i];
            }
        }
        return cur+1;
    }
 */

/* 加入k判断有几个重复的值
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int count = 1; 
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(count < 2){
                    nums[k] = nums[i];
                    count++;
                    k++;
                }
            }
            else{
                count = 1;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
*/

