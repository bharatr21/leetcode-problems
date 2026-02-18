class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s;
        while(n) {
            s += (n & 1) + '0';
            n >>= 1;
        }
        for(size_t i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i+1]) return false;
        }
        return true;
    }
};