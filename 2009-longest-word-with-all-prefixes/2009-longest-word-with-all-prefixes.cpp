class TrieNode {
    public:
        bool end;
        vector<TrieNode*> links;
        TrieNode() {
            end = false;
            for(char i = 'a'; i <= 'z'; i++) {
                links.push_back(NULL);
            }
        }
        TrieNode* get(char ch) {
            return links[ch - 'a'];
        }
        void put(char ch, TrieNode* node) {
            links[ch - 'a'] = node;
        }
        void setEnd() {end = true;}
        bool isEnd() {return end;}
};

class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string s) {
            TrieNode* node = root;
            for(char ch: s) {
                if(!node->get(ch)) {
                    node->put(ch, new TrieNode());
                }
                node = node->get(ch);
            }
            node->setEnd();
        }
        bool search(string s) {
            TrieNode* node = root;
            for(char ch: s) {
                if(!node->get(ch)) {
                    return false;
                }
                node = node->get(ch);
            }
            return node->isEnd();
        }
        bool isPrefix(string s) {
            TrieNode* node = root;
            for(char ch: s) {
                if(!node->get(ch)) {
                    return false;
                }
                node = node->get(ch);
            }
            return true;
        }
};

class Solution {
public:
    static bool cmp(string s1, string s2) {
        return (s1.size() == s2.size() ? s1 < s2 : s1.size() > s2.size());
    }
    string longestWord(vector<string>& words) {
        string res;
        Trie* trie = new Trie();
        for(string word: words) {
            trie->insert(word);
        }
        sort(words.begin(), words.end(), cmp);
        for(string word: words) {
            string tmp = "";
            tmp += word[0];
            int i = 1, n = word.size();
            while(trie->search(tmp) && i < n) {
                tmp += word[i++];
            }
            if(i == n) return word;
        }
        return res;
    }
};