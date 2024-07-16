class Solution {
public:
    bool solve(vector<int>& dp, string s, int idx, vector<string>& wordDict) {
        int n = s.size();
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx];
        string temp = s.substr(idx);
        for(string word: wordDict) {
            if(temp.rfind(word, 0) == 0) {
                if(solve(dp, s, idx + word.size(), wordDict)) return (dp[idx] = 1);
            }
        }
        return (dp[idx] = 0);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(dp, s, 0, wordDict);
    }
};