class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned int> cur(n+1, 0), next(n+1, 0);
        next[n] = 1;
        cur[n] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                cur[j] = next[j];
                if(s[i] == t[j]) cur[j] += next[j+1];
            }
            next = cur;
        }
        return cur[0];
    }
};