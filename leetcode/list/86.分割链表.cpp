    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* before = new ListNode(-1);
        ListNode* after = new ListNode(-1);
        ListNode *pb = before, *ba = after;

        for(auto p = head; p; p = p->next)
        {
            if(p->val < x) pb->next = p, pb = pb->next;
            else ba->next = p, ba = ba->next;
        }
        pb->next = after->next, ba->next = nullptr;
        return before->next;
    }