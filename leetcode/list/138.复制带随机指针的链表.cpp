    Node* copyRandomList(Node* head) {
        //使用O(1)的方法复制链表
        //第一步将复制的链表放到后一个链表的尾巴
        if(!head) return nullptr;
        for(auto p = head; p; p = p->next)
        {
            Node *node = new Node(p->val);
            node->next = p->next;
            p->next = node;
            p = node;
        }

        //设置node的random
        for(auto p = head; p; p = p->next->next)
        {
            Node *node = p->next;
            if(p->random ) node->random = p->random->next;
        }

        //分离深复制的链表
        Node* copy = head->next;
        for(auto p = head; p;)
        {
            Node* node = p->next;
            p->next = node->next;
            p = p->next;
            if(p)node->next = p->next;
        }
        return copy;
    }