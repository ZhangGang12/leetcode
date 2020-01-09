/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> map(n);
        map[0] = 1;
        for(int i = 1; i < n; i++){
            map[i] = map[i - 1]  * (i + 1);
        }
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
        }
        string res = "";
        int num;
        while(!nums.empty()){
            if(n - 2 >= 0 && map[n - 2] > 0)
            {
            num = (k - 1)/map[n - 2];
            k = k - num*map[n - 2];
            }
            else num = 0;
            res += '0' + nums[num];
            nums.erase(nums.begin()+ num);
            --n;
        }
        return res;
    }
};
// @lc code=end

