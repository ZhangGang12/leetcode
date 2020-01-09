/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
            if(!head) return NULL;
            ListNode* summy = new ListNode(-1);
            summy->next = head;

            ListNode* cur = head->next;
            head->next = NULL;

            while(cur){
                ListNode* p = summy;
                while(p->next != NULL && p->next->val < cur->val){
                    p = p->next;
                }

                ListNode* temp = cur->next;
                cur->next = p->next;
                p->next = cur;
                cur = temp;
            }
            return summy->next;
    }
};
// @lc code=end

