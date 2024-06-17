class Solution {
public:
    bool isSquare(int n) {
        return (int(sqrt(n)) == sqrt(n));
    }
    bool judgeSquareSum(int c) {
        int i;
        for(i = 0; i <= min(sqrt(INT_MAX), sqrt(c)); i++)
        {
            if(isSquare(c - i * i)) return true;
        }
        return false;
    }
};