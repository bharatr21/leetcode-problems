class Solution {
public:
    long long coloredCells(int n) {
        return (1 + 4 * ((long long)n * (n - 1) / 2));
    }
};