class Trie {
    struct Node {
        vector<Node*> links;
        int ct;
        Node(): links(26, NULL), ct(0) {}
    };
    Node* root;
    public:
        Trie() {root = new Node(); }
        void addWord(string& word) {
            Node* curr = root;
            for(char c: word) {
                if(!curr->links[c - 'a'])
                curr->links[c - 'a'] = new Node();
                curr = curr->links[c - 'a'];
                curr->ct++;
            }
        }
        int countPref(string& pref) {
            Node* curr = root;
            for(char c: pref) {
                if(!curr->links[c - 'a']) return 0;
                curr = curr->links[c - 'a'];
            }
            return curr->ct;
        }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(string& word: words) {
            trie.addWord(word);
        }
        return trie.countPref(pref);
    }
};