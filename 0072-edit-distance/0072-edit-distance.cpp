class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m == 0) return n;
        else if(n == 0) return m;
        vector<int> cur(n+1, 0), prev(n+1, 0);
        for(int j = 0; j <= n; j++) prev[j] = j;
        for(int i = 1; i <= m; i++) {
            cur[0] = i;
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    cur[j] = prev[j-1];
                }
                else {
                    cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
                }
            }
            prev = cur;
        }
        return prev[n];
    }
};