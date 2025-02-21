class Solution {
public:
    bool checkPal(string s, int st, int en) {
        for(int i = st, j = en; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return (checkPal(s, i + 1, j) || checkPal(s, i, j - 1));
            }
            i++;
            j--;
        }
        return true;
    }
};