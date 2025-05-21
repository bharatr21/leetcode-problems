class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ans = 0;
        int left = 0, right = 0;
        for(char ch: s) {
            if(ch == '(') left++;
            else right++;
            if(left == right) ans = max(ans, 2 * left);
            else if(right > left) {left = 0; right = 0;}
        }
        left = 0; right = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') left++;
            else right++;
            if(left == right) ans = max(ans, 2 * left);
            else if(left > right) {left = 0; right = 0;}
        }
        return ans;
    }
};