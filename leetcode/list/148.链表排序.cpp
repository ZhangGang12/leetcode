    ListNode* sortList(ListNode* head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n++;  //链表节点为n

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        for(int i = 1; i < n; i += i) //每次处理 i * 2长度的链表
        {
            auto cur = dummy; //从头节点的前一个开始
            for(int j = 0; j + i < n; j += i*2)
            {
                auto p = cur->next, q = cur->next;
                for(int k = 0; k < i; k++) q = q->next;
                
                int l = 0, r = 0;
                while(l < i && r < i && q && p)
                {
                    if(q->val < p->val)
                    {
                        cur->next = q; r++; q = q->next;
                    }else{
                        cur->next = p; l++; p = p->next;
                    }
                    cur = cur->next;
                }

                while(l < i && p) {cur->next = p; p = p->next; cur = cur->next;l++;}
                while(r < i && q) {cur->next = q; q = q->next; cur = cur->next;r++;}
                cur->next = q;
            }
        }
        return dummy->next;

    }