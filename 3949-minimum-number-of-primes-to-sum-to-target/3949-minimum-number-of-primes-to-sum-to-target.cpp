class Solution {
public:
    vector<int> sieve(int m) {
        int n = 10000;
        vector<int> mark(n+1, -1);
        vector<int> primes;
        int i = 2;
        while(primes.size() < m) {
            if(mark[i] == -1) {
                mark[i] = 1;
                primes.push_back(i);
                for(int j = i * i; j <= n; j += i) {
                    mark[j] = 0;
                }
            }
            i++;
        }
        return primes;
    }

    int solve(int n, vector<int>& dp, vector<int>& primes) {
        if(n <= 1) return 1001;
        if(dp[n] == 1) return 1;
        else if(dp[n] <= 1000) return dp[n];
        else {
            for(int pr: primes) {
                if(pr <= n) {
                    dp[n] = min(dp[n], 1 + solve(n - pr, dp, primes));
                }
            }
        }
        return dp[n];
    }

    int minNumberOfPrimes(int n, int m) {
        vector<int> primes = sieve(m);
        vector<int> dp(n+1, 1001);
        for(int el: primes) {
            if(el <= n) dp[el] = 1;
        }
        int ans = solve(n, dp, primes);
        return ((ans >= 1001) ? -1: ans);
    }
};