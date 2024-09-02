class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) {
            words.push_back(tmp);
        }
        unordered_map<char, string> mp;
        unordered_map<string, char> rmp;
        int n = pattern.size();
        if(words.size() != n) return false;
        for(int i = 0; i < n; i++) {
            char ch = pattern[i];
            string word = words[i];
            if(mp.count(ch) && mp[ch] != word) return false;
            if(rmp.count(word) && rmp[word] != ch) return false;
            else {
                mp[ch] = word;
                rmp[word] = ch;
            }
        }
        return true;
    }
};