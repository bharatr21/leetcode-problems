class Solution {
public:
    int differenceOfSums(int n, int m) {
        int d = 0, nd = 0;
        for(int i = m; i <= n; i += m) d += i;
        nd = (n * (n + 1) / 2) - d;
        return (nd - d);
    }
};