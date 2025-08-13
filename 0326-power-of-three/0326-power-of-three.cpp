class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int tmp = n;
        while(tmp > 1) {
            if(tmp % 3 && tmp > 1) return false;
            tmp = tmp / 3;
        }
        return (tmp == 1);
    }
};