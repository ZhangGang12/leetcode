    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* first = head, *second = head;
        while(first && second)
        {
            first = first->next;
            second = second->next;
            if(second) second = second->next;
            else return nullptr;

            if(first == second)
            {
                first = head;
                while(first != second)
                {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }
        return nullptr;
    }