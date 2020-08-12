class Solution {
public:
/**图的深复制
 * 思路：用一个hash来将原来的节点映射到复制后的新节点
 * 然后利用队列queue进行图的宽度优先搜索
 * 每次取出neighbors中的节点，如果没有映射，则进行创建并且加入到队列中。
 */
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node* , Node*> mp;
        queue<Node*> q;
        Node *node1 = new Node(node->val);
        mp[node] = node1;
        q.push(node);
        while(q.size())
        {
            Node *node2 = q.front();
            q.pop();
            for(auto t : node2->neighbors)
            {
               if(mp.count(t) == 0)
                {
                    Node *u = new Node(t->val);
                    mp[node2]->neighbors.push_back(u);
                    mp[t] = u;
                    q.push(t);
                }else mp[node2]->neighbors.push_back(mp[t]);
            }
        }
        return mp[node];
    }
};