/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len = 0;
        ListNode * temp = head;
        ListNode* end;
        while(temp){
            ++len;
            temp = temp->next;
        }
        temp = head;
        while(temp->next){
            temp = temp->next;
        }
        end = temp;
        while(k > len) k -= len;
        if(k == len) return head;
        temp = head;
        ListNode* first = head;
        end->next = head;
        k = len - k - 1;
        while(k > 0){
            first = first ->next;
            k--;
        }
        temp = first->next;
        first->next = NULL;
        return temp;
    }
};
// @lc code=end

