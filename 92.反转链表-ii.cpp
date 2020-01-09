/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       //迭代
       if(m == n) return head;
       ListNode* dummy = new ListNode(-1);
       ListNode* pre = dummy;
       dummy->next = head;
        //抵达反转链表的前一个节点
       for(int i = 0; i < m-1; i++)pre = pre->next;
       ListNode* cur = pre->next;
        //1 -> 2 -> 3 -> 4 -> 5 -> NULL
        //1 -> 3 -> 2 -> 4 -> 5 -> NULL
        //1 -> 4 -> 3 -> 2 -> 5 -> NULL
       for(int i = m; i < n; i++){
           ListNode* tmp = cur->next;
           //三次变化
           cur->next = tmp->next;
           tmp->next = pre->next;
           pre->next = tmp;
       }
      head = dummy->next;
      delete dummy;
      return head;
    }
};
// @lc code=end

//暴力数组
/*
       if(m == n) return head;
       vector<ListNode*> map;
       ListNode* cur = head;
       while(cur){
           map.push_back(cur);
           cur = cur->next;
       }
       map.push_back(NULL);
       int k = m;
       while(k < n){
           map[k]->next = map[k-1];
           ++k;
       }
       if(1 == m){
           map[0]->next = map[n];
           head = map[n-1];
       }else{
           map[m-2]->next = map[n-1];
           map[m-1]->next = map[n];
       }
       return head;
       */

