class Solution {
public:
    double myPow(double x, int n) {
        int sign = ((n < 0) ? -1 : 1);
        double res = 1, ans = 1, temp = x;
        n = abs(n);
        while(n) {
            if(n & 1) res = res * temp;
            temp = temp * temp;
            n = n >> 1;
        }
        return ((sign == -1) ? (1.0 / res): res);
    }
};