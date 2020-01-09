/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* one = new ListNode(NULL);
        ListNode* ot = one;
        ListNode* two = new ListNode(NULL);
        ListNode* tt = two;
        while(temp){
            if(temp->val < x) {
                ot->next = temp;
                ot = ot->next;
            }else{
                tt->next = temp;
                tt = tt->next;
            }
            temp = temp->next;
        }
        tt->next = NULL;
        ot->next = two->next;
        return one->next;
    }
};
// @lc code=end

