    ListNode* oddEvenList(ListNode* head) {
        //1 2 3 4 5 -> 1 3 5 2 4
        //分两部分将奇数分一部分，偶数分一部分
        //首先判断极端的情况
        if(!head || !head->next) return head; //保证第一个偶数可以取到
        ListNode *odd = head, *even = head->next, *even_head = head->next;
        for(auto p = head->next->next; p;)
        {
            odd->next = p, odd = p, p = p->next;
            if(p) {
                even->next = p, even = p, p = p->next;
            }
        }
        odd ->next = even_head, even->next = nullptr;
        return head;
    }
