class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, false);
        unordered_set<string> seen;
        dp[0] = true;
        for(string& word: wordDict) seen.insert(word); 
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && seen.count(s.substr(j, i-j))) {dp[i] = true; break;}
            }
        }
        return dp[n];
    }
};