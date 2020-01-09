/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool col = false;
        for(int i = 0; i < matrix.size(); i++){
            while(matrix[i][0] == 0){
                row = true;
                break;
            }
        }
        for(int j = 0; j < matrix[0].size(); j++){
            while(matrix[0][j] == 0){
                col= true;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } 
            }
        }
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                int i = 1;
                while(i < matrix.size()){
                    matrix[i][j] = 0;
                    ++i;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                int j = 1;
                while(j < matrix[0].size()){
                    matrix[i][j] = 0;
                    ++j;
                }
            }
        }
        if(row){
            int i = 0;
            while(i < matrix.size()){
                matrix[i][0] = 0;
                ++i;
            }
        }
        if(col){
            int j = 0;
            while(j < matrix[0].size()){
                matrix[0][j] = 0;
                ++j;
            }
        }
        
    }
};
// @lc code=end
/*code start
vector<vector<int>> map;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) map.push_back({i,j});
            }
        }
        int k = 0;
        while(k < map.size()){
            int i = map[k][0];
            int j = map[k][1];
            for(int a = 0; a < matrix.size(); a++){
                matrix[a][j] = 0;
            }
            for(int a = 0; a < matrix[0].size(); a++){
                matrix[i][a] = 0;
            }
            ++k;
        }
  code end      */
