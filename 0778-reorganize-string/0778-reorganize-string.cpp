class Solution {
public:
    string reorganizeString(string s) {
        vector<int> fre(26, 0);
        for(char ch: s) fre[ch - 'a']++;
        int mx = -1, letter = 0;
        for(int i = 0; i < 26; i++) {
            if(mx < fre[i]) {
                mx = fre[i];
                letter = i;
            }
        }
        if(fre[letter] > (s.size() + 1) / 2) return "";
        string res = s;
        int idx = 0;
        while(fre[letter]) {
            res[idx] = char(letter + 'a');
            idx += 2;
            fre[letter]--;
        }
        for(int i = 0; i < 26; i++) {
            while(fre[i]) {
                if(idx >= s.size()) idx = 1;
                res[idx] = char(i + 'a');
                idx += 2;
                fre[i]--;
            }
        }
        return res;
    }
};