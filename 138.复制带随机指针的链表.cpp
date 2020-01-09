/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include "INCLUDE.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* temp = head;
        unordered_map<Node*,Node*>map;
        Node* root = new Node(temp->val);
        map[temp] = root;
        Node* tp = root;
        temp = temp->next;
        while(temp){
            Node* cur = new Node(temp->val);
            tp->next = cur;
            tp = cur;
            map[temp] = cur;
            temp = temp->next;
        }
        temp = head;
        tp = root;
        while(temp){
            if(temp->random)
            tp->random = map[temp->random];
            temp = temp->next;
            tp = tp->next;
        }
        return root;
    }
};
// @lc code=end

