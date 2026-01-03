class Solution {
public:
    int hammingWeight(int n) {
        int ct = 0;
        while(n) {
            if(n & 1) ct++;
            n >>= 1;
        }
        return ct;
    }
};