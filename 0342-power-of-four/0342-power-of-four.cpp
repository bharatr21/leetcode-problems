class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        int tmp = n;
        while(tmp > 1) {
            if(tmp % 4) return false;
            tmp = tmp / 4;
        }
        return (tmp == 1);
    }
};