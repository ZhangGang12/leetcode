/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //桶排序：将nums中小于1或者大于n的置1
        //将nums中在区间1~n中的数字与对应下标位置的元素进行置换，然后重复
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != i+1){
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i]-1])
                break;
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != (i+1)) return i+1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end
/*
    int firstMissingPositive(vector<int>& nums) {
        //第一步：判断1是否存在，如果不存在直接返回1，如果存在将<=0 或者 >n的元素变成1，此时数组所有数都>0且都<= n;
        //第二步：遍历整个数组，将第i号元素视作nums下标->nums[nums[i]] ,使其变为复数，表示nums[a] a存在;
        //第三部：从1开始遍历整个数组，遍历到正数推出并返回下标，再判断0处是否>0，若前面都符合则返回n+1;
        int n = nums.size();
        int contains = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                ++contains;
                break;
            }
        }
        if(contains == 0)return 1;
        if(n == 1) return 2;
        for(int i = 0; i < n; i++)
            if((nums[i] <= 0) || (nums[i] > n))
            nums[i] = 1;
        for(int i = 0; i < n; ++i){
            int a = abs(nums[i]);
            if(a == n)
                nums[0] = -abs(nums[0]);
            else
                nums[a] = -abs(nums[a]);
        }

        for(int i = 1; i < n; i++){
            if(nums[i] > 0) return i;
        }
        if(nums[0] > 0) return n;

        return n+1;
    }
 */
/*
public:
    int firstMissingPositive(vector<int>& nums) {
        //桶排序：将nums中小于1或者大于n的置1
        //将nums中在区间1~n中的数字与对应下标位置的元素进行置换，然后重复
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] != i+1){
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i]-1])
                break;
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != (i+1)) return i+1;
        }
        return nums.size() + 1;
    }
};
*/