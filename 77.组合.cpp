/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res,temp,n,1,k);
        return res;
    }

    void dfs(vector<vector<int>> &res,vector<int> temp, int& n, int i, int k){
        
        if(k == 0){
            res.push_back(temp);
            return;
        }
        for(int j = i ; j <= n - k + 1; j++){
            temp.push_back(j);
            dfs(res,temp,n,j+1,k-1);
            temp.pop_back();
        }
    }
};
// @lc code=end

