class Solution {
public:
    int smallestNumber(int n) {
        int ct = 0, tmp = n;
        while(tmp) {
            ct++;
            tmp >>= 1;
        }
        return (1 << ct) - 1;
    }
};