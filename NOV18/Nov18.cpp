class Trie {
public:
    Trie* child[26];
    bool wordEnd;
    Trie() {
        wordEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(char c: word){
            if(curr->child[c - 'a'] == nullptr){
                curr->child[c- 'a'] = new Trie();
            }
            curr = curr->child[c - 'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(char c :word){
            if(curr->child[c - 'a'] == nullptr) return false;
            curr = curr->child[c - 'a'];
        }
        if(curr->wordEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c :prefix){
            if(curr->child[c - 'a'] == nullptr) return false;
            curr = curr->child[c - 'a'];
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
