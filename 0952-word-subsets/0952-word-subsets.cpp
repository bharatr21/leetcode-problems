class Solution {
public:
    bool isSubset(vector<int> sub, string s) {
        vector<int> sup(26, 0);
        for(char ch: s) sup[ch - 'a']++;
        for(auto i = 'a'; i <= 'z'; i++) {
            if(sup[i - 'a'] < sub[i - 'a']) return false;
        }
        return true;

    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        string s2;
        vector<int> sub(26, 0);
        for(string word: words2) {
            vector<int> tmp(26, 0);
            for(char ch: word) tmp[ch - 'a']++;
            for(int i = 0; i < 26; i++) {
                sub[i] = max(sub[i], tmp[i]);
            }
        }
        for(string word: words1) {
            if(isSubset(sub, word)) res.push_back(word);
        }
        return res;
    }
};