/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int len = matrix[0].size();
        int k = row * len;
        int i = 0, j = k - 1;
        while(i <= j){
            int mid = (i + j)/2;
            int a = mid/len;
            int b = mid%len;
            if(target == matrix[a][b]) return true;
            else if(target < matrix[a][b]) j = mid - 1;
            else if(matrix[a][b] < target) i = mid + 1;
        }
        return false;
    }
};
// @lc code=end

