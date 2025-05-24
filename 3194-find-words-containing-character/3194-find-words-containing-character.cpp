class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        vector<unordered_set<char>> charsets(n);
        for(int i = 0; i < n; i++) {
            for(char ch: words[i]) {
                charsets[i].insert(ch);
            }
        }
        
        for(int idx = 0; idx < n; idx++) {
            if(charsets[idx].count(x)) res.push_back(idx);
        }
        return res;
    }
};