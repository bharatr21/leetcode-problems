class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long abc = 6, aba = 6, n_abc = abc, n_aba = aba;
        for(int i = 2; i <= n; i++) {
            n_aba = (3 * aba + 2 * abc) % MOD;
            n_abc = (2 * aba + 2 * abc) % MOD;
            aba = n_aba;
            abc = n_abc;
        }
        return (abc % MOD + aba % MOD) % MOD;
    }
};