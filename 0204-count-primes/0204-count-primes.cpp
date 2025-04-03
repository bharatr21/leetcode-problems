class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        int ct = 0;
        for(int i = 2; i < n; i++) {
            if(prime[i]) {
                ct++;
                for(long j = 1L * i * i; j < n; j += i) prime[j] = false;
            }
        }
        return ct;
    }
};