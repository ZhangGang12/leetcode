    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //思路 一个从A出发 到nullptr后从B出发，另一个相反，最后会相遇，相遇点则是交点
        ListNode* pa = headA, *pb = headB;
        while(pa != pb)
        {
            if(pa) pa = pa->next;
            else pa = headB;
            if(pb) pb = pb->next;
            else pb = headA;
        }  //最后一定会相交，无论是否时nullptr还是不是nullptr
        return pa;
    }