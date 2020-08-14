class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur)
        {
            auto p =cur;
            for(int i = 0; p && i < k; i++) p = p->next;
            if(!p) break;

            ListNode* t = cur->next;
            ListNode *a = cur->next, *b = a->next;        
            for(int i = 1; i < k; i++)
            {
                ListNode *c = b->next;
                b->next = a;
                cur->next = b;
                a = b, b = c;
            }
            t->next = b;
            cur = t;
        }
        return dummy->next;
        
    }
};