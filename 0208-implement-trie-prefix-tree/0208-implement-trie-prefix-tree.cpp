class TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
public:
    TrieNode() {
        isEnd = false;
        for(char i = 'a'; i <= 'z'; i++) children.push_back(NULL);
    }
    
    int key(char ch) {
        return (ch - 'a');
    }

    void setEnd() {
        isEnd = true;
    }

    bool getEnd() {
        return isEnd;
    }

    bool contains(char ch) {
        return (children[key(ch)] != NULL);
    }

    void set(char ch, TrieNode* node) {
        children[key(ch)] = node;
    }

    TrieNode* get(char ch) {
        return children[key(ch)];
    }
};

class Trie {
    TrieNode* trie;
public:
    Trie() {
        trie = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = trie;
        for(char ch: word) {
            if(!node->contains(ch))
                node->set(ch, new TrieNode());
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = trie;
        for(char ch: word) {
            if(node->contains(ch))
                node = node->get(ch);
            else
                return false;
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = trie;
        for(char ch: prefix) {
            if(node->contains(ch))
                node = node->get(ch);
            else
                return false;
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