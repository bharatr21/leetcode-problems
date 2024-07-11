class Solution {
public:
    int lcs(vector<vector<int>>& dp, string text1, string text2, int i, int j) {
        int res;
        if(i == 0 || j == 0) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        else if(text1[i-1] == text2[j-1]) res = 1 + lcs(dp, text1, text2, i-1, j-1);
        else res = max(lcs(dp, text1, text2, i, j-1), lcs(dp, text1, text2, i-1, j));
        return (dp[i][j] = res);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return lcs(dp, text1, text2, m, n);
    }
};
