/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
struct Node {
    Node* next[26];
    bool isword = false;
};
class Trie {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *tmp = root;
        for(int i = 0; i < word.size(); i++){
            if( tmp->next[word[i] - 'a'] == NULL){
                tmp->next[word[i] - 'a'] = new Node();
            }
            tmp = tmp->next[word[i] - 'a'];
        }
        tmp->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *tmp = root;
        int i = 0;
        while( i<word.size() && tmp){
            if(tmp->next[word[i]-'a'] == NULL) return false;
            tmp = tmp->next[word[i]-'a'];
            ++i;
        }
        return  tmp->isword ;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(int i = 0; i < prefix.size(); i++){
            if(tmp->next[prefix[i] - 'a' ] == NULL) return false;
            tmp = tmp->next[prefix[i] - 'a'];
        }
        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

