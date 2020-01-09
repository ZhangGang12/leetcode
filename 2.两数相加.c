/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* a = l1;
    struct ListNode* b = l2;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* cur = head;
    int flage = 0;
    while(a != NULL||b != NULL){
        int sum = 0;
        if(a){sum += a->val; a = a->next;}
        if(b){sum += b->val; b = b->next;}
        sum += flage;
        if(sum > 9){
            sum -= 10;
            flage = 1;
        }else {
            flage = 0;
        }
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = sum;
        cur->next = tmp;
        cur = cur->next;
    }
    if(flage == 1) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = 1;
        cur->next = tmp;
    }
    struct ListNode* DelectPtr = head;
    head = head->next;
    free(DelectPtr);
    return head;
}


// @lc code=end

