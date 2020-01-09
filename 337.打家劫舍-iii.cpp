/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	unordered_map <TreeNode*, int> map;
public:
    int rob(TreeNode* root) {
        int res = 0;
		if (!root) return 0;
		if (!root->left && !root->right) return root->val;
		if (map.count(root)) return map[root];
		int head = 0;
		head += root->val;
		if (root->left) head += rob(root->left->right) + rob(root->left->left);
		if (root->right) head += rob(root->right->right) + rob(root->right->left);
		int nothead = rob(root->left) + rob(root->right);
		res = head > nothead ? head : nothead;
		map[root] = res;
        return res;
    }
};
// @lc code=end

