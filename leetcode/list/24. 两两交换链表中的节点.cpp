class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy; p->next && p->next->next; )
        {
            ListNode* a = p->next, *b = p->next->next;
            a->next = b->next;
            b->next = a;
            p->next = b;
            p = a;
        }
        return dummy->next;
    }
};