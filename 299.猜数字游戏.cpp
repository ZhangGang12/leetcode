/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int A = 0;
        int B = 0;
        unordered_map <char,int> map;
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]) ++A;
            map[secret[i]]++;
        }
        for(int i = 0; i < guess.size(); ++i){
            if(map[guess[i]] > 0){
                ++B;
                map[guess[i]]--;
            }
        }
        res += to_string(A);
        res.push_back('A');
        res += to_string(B-A);
        res.push_back('B');
        return res;
    }
};
// @lc code=end

