class Solution {
public:
    string bin(int n) {
        string s;
        while(n) {
            s += ((n & 1) ? '1' : '0');
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int concatenatedBinary(int n) {
        string rstr;
        int res = 0, pwr = 1;
        int MOD = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            rstr += bin(i);
        }
        int sz = rstr.size();
        for(int i = sz - 1; i >= 0; i--) {
            if(rstr[i] == '1') {
                res = (res + pwr) % MOD;
            }
            pwr = (pwr << 1) % MOD;
        }
        return (res % MOD);
    }
};