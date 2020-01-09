/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Imax = 1; 
        int Imin = 1;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                int tmp = Imax;
                Imax = Imin;
                Imin = tmp;
            }
            Imax = max(Imax*nums[i],nums[i]);
            Imin = min(Imin*nums[i],nums[i]);

            res = max(res,Imax);
        }
        return res;

    }
};
// @lc code=end

