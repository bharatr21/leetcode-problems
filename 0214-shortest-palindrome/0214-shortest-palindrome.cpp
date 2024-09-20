class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        int left = 0;
        for(int right = n - 1; right >= 0; right--) {
            if(s[left] == s[right]) left++;
        }
        if(left == n) return s;
        string nPal = s.substr(left);
        string res = string(nPal);
        reverse(res.begin(), res.end());
        return (res + shortestPalindrome(s.substr(0, left)) + nPal);
    }
};