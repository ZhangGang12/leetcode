/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        //dp[]
        vector<int> res(num+1);
        for(int i = 1; i <= num; i++){
            res[i] = res[i>>1] + (i & 1);
        }
        return res;
    }
};
// @lc code=end
/*暴力想法
vector<int> res;
        for(int i = 0; i <= num; i++){
            res.push_back(hammingWeight(i));
        }
        return res;
    }

    int hammingWeight(int n) {
        int res;
        for(res = 0; n != 0; ++res) n &= n - 1;
        return res;
    }
    */
