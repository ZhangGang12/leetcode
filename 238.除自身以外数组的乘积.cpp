/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> l(len,1), r(len,1);
        int left = 1,right = 1;
        for(int i = 0; i < len - 1; i++){
            left *= nums[i];
            l[i+1] = left;
            right *= nums[len-1-i];
            r[len-2-i] = right;
        }
        

        for(int i = 0; i < len; i++){
            l[i] = l[i]*r[i];
        }
        return l;
    }
};
// @lc code=end
//总结
