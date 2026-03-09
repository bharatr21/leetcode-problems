#define ll long long
class Solution {
public:
    int numberOfStableArrays(int l_zero, int l_one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<vector<ll>>> dp(l_zero+1, vector<vector<ll>>(l_one+1, vector<ll>(2, 0)));
        for(int i = 0; i <= min(l_zero, limit); i++) dp[i][0][0] = 1;
        for(int j = 0; j <= min(l_one, limit); j++) dp[0][j][1] = 1;
        for(int i = 1; i <= l_zero; i++) {
            for(int j = 1; j <= l_one; j++) {
                dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1];
                if(i > limit) dp[i][j][0] -= dp[i - (limit + 1)][j][1];
                if(j > limit) dp[i][j][1] -= dp[i][j - (limit + 1)][0];
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[l_zero][l_one][0] + dp[l_zero][l_one][1]) % mod;
    }
};