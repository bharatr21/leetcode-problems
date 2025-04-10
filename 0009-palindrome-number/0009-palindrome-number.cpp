class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = 0, tmp = x;
        while(tmp) {
            if(rev >= INT_MAX / 10) return false;
            rev = rev * 10 + (tmp % 10);
            tmp /= 10;
        }
        return (rev == x);
    }
};