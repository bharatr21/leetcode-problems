class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string res;
        if(n <= 1) return res;
        res = palindrome;
        for(int i = 0, j = n - 1; i <= j; i++, j--) {
            if(res[i] == res[j] && res[i] == 'a') continue;
            else if(i != j) {res[i] = 'a'; return res;}
        }
        res[n-1] = 'b';
        return res;
    }
};