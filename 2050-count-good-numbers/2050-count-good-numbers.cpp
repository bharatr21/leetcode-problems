class Solution {
public:
    int modexp(int base, long long exp, int mod) {
        long long tmp = exp;
        long long res = 1;
        base = base % mod;
        while(tmp) {
            if(tmp & 1) res = ((long long)(res % mod) * (base % mod)) % mod;
            base = ((long long)(base % mod) * (base % mod)) % mod;
            tmp >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        int MOD = 1000000007;
        return ((long long)(modexp(5, (n + 1) / 2, MOD) % MOD) * (modexp(4, n/2, MOD) % MOD) % MOD);
    }
};