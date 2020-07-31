    void reorderList(ListNode* head) {  //缺点 代码很乱，命名没有统一风格，有待重构
        //1 2 3 4 -> 1 4 2 3 
        //我们可以分两步走，将后半部分的链表进行反转。然后一个从前往后走，一个从后往前走，依次插入
        //首先要找到链表的中间节点然后将其反转
        //利用快慢指针的思想，找到中间节点，对于 1 2 3 4 我们要确定的节点是3 对于 1 2 3 4 5 我们要确定的节点是3 
        if(!head || !head->next) return;
        ListNode* fisrt = head, *second = head;
        while(second && second->next)
        {
            fisrt = fisrt->next;
            second = second->next->next;
        }
        //此时first就在3的位置
        //开始链表翻转
        ListNode* pre = nullptr;
        ListNode* a = fisrt, *b = fisrt->next;
        while(b)
        {
            pre = b->next;
            b->next = a;
            a = b;
            b = pre;
        }
        //a现在是后面链表的表头，，即4 或者 5的位置
        fisrt->next = nullptr;
        fisrt = head;
        while(a->next) //因为3指向0，当a走到指向0 的点时就结束循环
        {
            ListNode* c =  a->next;
            a->next = fisrt->next;
            fisrt->next = a;
            fisrt = fisrt->next->next;
            a = c;
        }
    }