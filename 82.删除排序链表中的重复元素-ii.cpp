/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        //排除头重复
        while(head && head->next){
            if(head->val != head->next->val)break;
            else{
                ListNode* temp = head;
                head = head->next;
                while(head->next){
                    if(temp->val != head->val)break;
                    else head = head->next;
                }
                if(head->val == temp->val) head = head->next;
            }
        }
        //
        ListNode* first = head;
        ListNode* second = head;
        ListNode* cur = head;
        while(cur&&cur->next){
            if(cur->val == cur->next->val){
                second = cur;
                while(cur->next){
                    if(second->val != cur->val) break;
                    else cur = cur->next;
                }
                if(cur->val == second->val) cur = cur->next;
                first->next = cur;
            }
            else {
                first = cur;
                cur = cur->next;
                }
        }
        return head;
    }
};
// @lc code=end

