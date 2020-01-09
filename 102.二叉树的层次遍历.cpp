/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};
// @lc code=end
/*
 vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> Q;
        TreeNode* p;
        Q.push(root);
        while(Q.empty() == 0){
            vector<int> a;
            int width = Q.size();
            for( int i = 0; i < width; i++){
                p = Q.front();
                a.push_back(p->val);
                Q.pop();
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            res.push_back(a);
        }
        return res;*/
