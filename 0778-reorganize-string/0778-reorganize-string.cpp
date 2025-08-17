class Solution {
public:
    string reorganizeString(string s) {
        vector<int> fre(26, 0);
        int n = s.size(), mx = 0;
        char cur;
        for(char ch: s) fre[ch - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(mx < fre[i]) {
                mx = fre[i];
                cur = i + 'a';
            }
        }
        if(mx > (n + 1) / 2) return "";
        string res = s;
        int idx = 0;
        while(fre[cur - 'a'] > 0) {
            res[idx] = cur;
            idx += 2;
            fre[cur - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            while(fre[i] > 0) {
                if(idx >= n) idx = 1;
                res[idx] = (char)(i + 'a');
                idx += 2;
                fre[i]--;
            }
        }
        return res;
    }
};