class TrieNode {    
public:
    bool end;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        end = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();   
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch: word) {
            if(node->children.find(ch) == node->children.end()) 
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->end = true;
    }
    
    bool searchHelper(string word, TrieNode* node) {
        int n = word.size(), i;
        for(i = 0; i < n; i++) {
            char ch = word[i];
            if(node->children.find(ch) == node->children.end()) {
                if(ch == '.') {
                    for(auto u: node->children) {
                        if(searchHelper(word.substr(i + 1), u.second)) return true;
                    }
                }
                return false;
            } else {
                node = node->children[ch];
            }
        }
        return node->end;
    }

    bool search(string word) {
        TrieNode* node = root;
        if(!node) return false;
        return searchHelper(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */