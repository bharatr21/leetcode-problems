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
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return edit(dp, word1, word2, m, n);
    }
};