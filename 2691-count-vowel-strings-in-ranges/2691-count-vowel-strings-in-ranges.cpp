class Solution {
public:
    bool startEndVowel(string word) {
        int n = word.size();
        char start = word[0];
        char end = word[n - 1];
        bool st = false, en = false;
        switch(start) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {st = true; break;}
            default: {st = false; break;}
        }
        switch(end) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {en = true; break;}
            default: {en = false; break;}
        }
        return (st && en);
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;
        int n = words.size();
        vector<bool> mask(n, false);
        vector<int> pre(n+1, 0);
        for(int i = 0; i < n; i++) {
            mask[i] = startEndVowel(words[i]);
        }
        pre[0] = mask[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + mask[i];
        }
        for(vector<int> query: queries) {
            int st = query[0], en = query[1];
            if(st == 0) res.push_back(pre[en]);
            else res.push_back(pre[en] - pre[st - 1]);
        }
        return res;
    }
};