class Solution {
public:
    double expo(double x, long long n) {
        if(n < 0) {
            x = 1.0 / x;
            n *= -1;
        }
        if(x == 1.0) return 1.0;
        double res = 1.0;
        while(n) {
            if(n & 1) res *= x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        return expo(x, (long long)n);
    }
};