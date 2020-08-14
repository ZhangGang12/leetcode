class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //堆排 小根堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> hp;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])hp.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(hp.size())
        {
            auto t = hp.top();
            hp.pop();
            cur->next = t;
            cur = cur->next;
            t = t->next;
            if(t) hp.push(t);
        }
        return dummy->next;
    }
};