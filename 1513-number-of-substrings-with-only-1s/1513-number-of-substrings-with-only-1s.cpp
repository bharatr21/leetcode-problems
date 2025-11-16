
class Solution {
public:
    typedef long long ll;
    int numSub(string s) {
        ll mod = 1000000007;
        ll res = 0, n1 = 0;
        for(char ch: s) {
            if(ch == '0') {
                if(n1) res += ((n1 % mod) * ((n1 + 1) % mod) % mod) / 2;
                n1 = 0;
            }
            else n1++;
        }
        if(n1) res += ((n1 % mod) * ((n1 + 1) % mod) % mod) / 2;
        return (int)res;
    }
};