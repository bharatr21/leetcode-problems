class Solution {
public:
    int solve(vector<vector<int>>& dp, int n, int cur, int pasten) {
        if(cur == n) return 0;
        if(cur > n) return 1001;
        int res;
        int opt1, opt2;
        if(dp[cur][pasten] != -1) return dp[cur][pasten];
        //Choose between two options: 
        //a) Paste existing first, copy all after appending
        //b) Copy all existing first and paste existing (append)
        opt1 = 2 + solve(dp, n, cur * 2, cur);
        opt2 = 1 + solve(dp, n, cur + pasten, pasten);
        res = min(opt1, opt2);
        return (dp[cur][pasten] = res);
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return 1 + solve(dp, n, 1, 1);
    }
};