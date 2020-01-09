/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include "INCLUDE.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dmmy = new ListNode(-1);
        dmmy->next = head;
        ListNode* cur = dmmy->next;
        ListNode* first = dmmy;
        while(cur){
            if(cur->val == val){
                cur = cur->next;
                first->next = cur;
            }else{
                first = first->next;
                cur = cur->next;
            }
        }
        return dmmy->next;
    }
};
// @lc code=end

