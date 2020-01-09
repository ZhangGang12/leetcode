/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        vector<ListNode*> map;
        ListNode* temp = head;
        while(temp){
            map.push_back(temp);
            temp = temp->next;
        }
        int len = map.size() - 1; //3
        if(len <= 1) return;
        temp = head;
        int star = 1;
        while(star < len) // 2 2
        {
            temp->next = map[len];
            temp = temp->next;
            --len;
            temp->next = map[star];
            temp = temp->next;
            ++star;
        }
        if( star == len) {
            temp->next = map[star];
            temp = temp->next;
            }
            temp->next = NULL;

    }
};
// @lc code=end

