class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};
class Trie{
    TrieNode* root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i] - 'a';
            if(!p -> child[k]){
                p -> child[k] = new TrieNode();
            }
            p = p ->child[k];
        }
        p ->isWord = true;
    }
    
    bool search(string word, bool prefix = false){
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i] - 'a';
            if(!p -> child[k]){
                return false;
            }
            p = p -> child[k];
        }
        if(prefix == false){
            return p -> isWord;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */