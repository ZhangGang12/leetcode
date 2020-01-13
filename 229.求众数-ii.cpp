/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        if(size == 0) return res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0; //候选数a,b
        for(auto num : nums){
            if(num == a){
                ++cnt1;
            }else if(num == b){
                ++cnt2;
            }else if(cnt1 == 0){
                a = num;
                ++cnt1;
            }else if(cnt2 == 0){
                b = num;
                ++cnt2;
            }else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num == a){
                ++cnt1;
            }else if(num == b){
                ++cnt2;
            }
        }
        if(cnt1 > size / 3){
            res.push_back(a);
        }
        if(cnt2 > size / 3){
            res.push_back(b);
        }
        return res;
    }
};
// @lc code=end
/*   
    //哈希表
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> res;
        int n = nums.size()/3;
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]]++;
            if(map[nums[i]] > n ) {
                res.push_back(nums[i]);
                map[nums[i]] = INT_MIN;
            }
        }
        return res;
    }
 */
/*
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        if(size == 0) return res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0; //候选数a,b
        for(auto num : nums){
            if(num == a){
                ++cnt1;
            }else if(num == b){
                ++cnt2;
            }else if(cnt1 == 0){
                a = num;
                ++cnt1;
            }else if(cnt2 == 0){
                b = num;
                ++cnt2;
            }else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num == a){
                ++cnt1;
            }else if(num == b){
                ++cnt2;
            }
        }
        if(cnt1 > size / 3){
            res.push_back(a);
        }
        if(cnt2 > size / 3){
            res.push_back(b);
        }
        return res;
    }
 */
