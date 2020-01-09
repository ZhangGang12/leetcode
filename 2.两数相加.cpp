/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        ListNode* a = l1;
        ListNode* b = l2;
        int flage = 0;
        while(a||b){
            int sum = 0;
            if(a){ sum += a->val; a = a->next;}
            if(b){ sum += b->val; b = b->next;}
            sum += flage;
            if(sum > 9){
                sum -= 10;
                flage = 1;
            }else{flage = 0;}
            ListNode* tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
        }
        if(flage == 1) {
            ListNode* tmp = new ListNode(1);
            cur->next = tmp;
        }
        ListNode* DeletePtr = head;
        head = head->next;
        delete DeletePtr;
        return head;
    }
};
// @lc code=end

