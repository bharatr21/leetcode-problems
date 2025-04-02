class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int tmp = x;
        int sgn = ((tmp < 0) ? -1 : 1);
        if(tmp == INT_MIN) return 0;
        tmp = abs(tmp);
        while(tmp) {
            if(res * 10L >= INT_MAX) return 0;
            res = res * 10 + (tmp % 10);
            tmp = tmp / 10;
        }
        return sgn * res;
    }
};