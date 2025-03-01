class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int res = n + 1;
        vector<int> fre(26, 0), idx(26, 0);
        int i = 0;
        for(char ch: s) {
            fre[ch - 'a']++;
            idx[ch - 'a'] = i++;
        }
        for(int i = 0; i < 26; i++) {
            if(fre[i] == 1) res = min(res, idx[i]);
        }
        return ((res > n) ? -1: res);
    }
};