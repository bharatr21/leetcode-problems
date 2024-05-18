class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end;
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
            if(!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchHelper(word, node);
    }

    bool searchHelper(string word, TrieNode* node) {
        int n = word.size(), i;
        for(i = 0; i < n; i++) {
            char ch = word[i];
            if(!node->children.count(ch)) {
                if(ch == '.') {
                    for(auto el: node->children) {
                        TrieNode* child = el.second;
                        if(searchHelper(word.substr(i + 1), child)) return true;
                    }
                }
                return false;
            } 
            else {
                node = node->children[ch];
            }
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */