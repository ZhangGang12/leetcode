class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //遍历所有节点，得到节点大小size 
        //可能会删除头节点所以引入哨兵节点
        int size = 0;
        for(auto p = head; p ; p = p->next) size++;
        size -= n ;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        for(int i = 0; i < size; i++) cur = cur->next;
        cur->next = cur->next->next;
        return dummy->next;
    }
};

//快慢指针法
// 1 2 3 4 5 删除倒数第2个节点
// 0 1 2 3 4 5 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针法
        ListNode *dummy = new ListNode(-1);
        ListNode* f = dummy, *s = dummy;
        dummy->next = head;
        for(int i = 0; i < n && f; i++) f = f->next;
        while(f->next) 
        {
            f = f->next;
            s = s->next;
        }
        s->next = s->next->next;
        return dummy->next;
    }
};