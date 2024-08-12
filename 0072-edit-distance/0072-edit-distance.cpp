class Solution {
public:
    int edit(vector<vector<int>>& dp, string word1, string word2, int idx1, int idx2) {
        int m = word1.size(), n = word2.size();
        int res;
        if(idx1 == 0) return idx2;
        else if(idx2 == 0) return idx1;
        else if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(word1[idx1-1] == word2[idx2-1]) {
            res = edit(dp, word1, word2 ,idx1 - 1, idx2 - 1);
        }
        else {
            res = 1 + min(edit(dp, word1, word2, idx1 - 1, idx2 - 1), 
            min(edit(dp, word1, word2, idx1 - 1, idx2), 
            edit(dp, word1, word2, idx1, idx2 - 1)));
        }
        return (dp[idx1][idx2] = res);
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m == 0) return n;
        else if(n == 0) return m;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++) dp[i][0] = i;
        for(int j = 1; j <= n; j++) dp[0][j] = j;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};