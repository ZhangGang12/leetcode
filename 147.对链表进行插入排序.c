/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if(head == NULL)
        return head;

    struct ListNode *headNULL = malloc(sizeof(struct ListNode));
    headNULL->next = head;

    struct ListNode *current = head->next;
    head->next = NULL;

    while(current != NULL){
        struct ListNode *p = headNULL;
        while(p->next != NULL && p->next->val < current->val){
            p = p->next;
        }
       //p为待插入位置前一节点的指针
     
        struct ListNode *tmp = current->next;
        current->next = p->next;
        p->next = current;
        current = tmp;
    }
  //返回首节点
    return headNULL->next;
}



// @lc code=end

