/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
#include "INCLUDE.h"
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            if(p || q) return false;
            return true;
        }
        if(p->val != q->val) return false;
        
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        return (left&&right);
    }
};
// @lc code=end

