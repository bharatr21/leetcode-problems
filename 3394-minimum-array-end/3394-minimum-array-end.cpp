class Solution {
public:
    long long merge(int x, int v) {
        long long res = x;
        while(--v) {
            res = (res + 1) | x;
        }
        return res;
    }

    long long minEnd(int n, int x) {
        return merge(x, n);
    }
};