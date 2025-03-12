class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if(k > n) return 0;
        vector<int> hash(26, 0);
        int rep = 0, res = 0;
        for(int i = 0; i < k; i++) {
            if(++hash[s[i] - 'a'] == 2) rep++;
        }
        if(!rep) res++;
        for(int i = k; i < n; i++) {
            if(--hash[s[i-k] - 'a'] == 1) rep--;
            if(++hash[s[i] - 'a'] == 2) rep++;
            if(!rep) res++;
        }
        return res;
    }
};