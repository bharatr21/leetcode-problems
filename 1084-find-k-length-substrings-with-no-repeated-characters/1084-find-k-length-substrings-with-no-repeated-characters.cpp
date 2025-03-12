class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if(k > n) return 0;
        vector<int> hashs(26, 0);
        int rep = 0, res = 0;
        for(int i = 0; i < k; i++) {
            if(++hashs[s[i] - 'a'] == 2) rep++;
        }
        if(!rep) res++;
        for(int i = k; i < n; i++) {
            if(--hashs[s[i-k] - 'a'] == 1) rep--;
            if(++hashs[s[i] - 'a'] == 2) rep++;
            if(!rep) res++;
        }
        return res;
    }
};