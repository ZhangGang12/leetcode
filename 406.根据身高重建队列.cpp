/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include "INCLUDE.h"
// @lc code=start
class Solution {

public:
//比较器
 static bool comparator(const vector<int>& a, const vector<int>& b) {
		if (a[0] > b[0]) return true;
		if (a[0] == b[0] && a[1] < b[1]) return true;
		return false;
	}
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comparator);

		vector<vector<int>> res;
		for (int i = 0; i < people.size(); i++) {
			res.insert(res.begin() + people[i][1], people[i]);
		}
        return res;
    }
    
};
// @lc code=end

