/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct Node{
        bool isword = false;
        Node* next[27] = {};
    };

class WordDictionary {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
      root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
       Node* tmp = root;
       for(auto w : word){
           if(tmp->next[w - 'a'] == NULL){
               Node* tt = new Node();
               tmp->next[w - 'a'] = tt;
           }
           tmp = tmp->next[w - 'a'];
       }
       tmp->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word,root,0);
    }

    bool dfs(string &word, Node* root, int i){
        if(!root) return false;
        if(i >= word.size()) return root->isword;
        if(word[i]!= '.'){
            if(root->next[word[i] - 'a']){
                return dfs(word, root->next[word[i] - 'a'], i+1);
            }
            else return false;
        }
        for(auto t : root->next){
            if(t){
                if(dfs(word, t, i+1)) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

