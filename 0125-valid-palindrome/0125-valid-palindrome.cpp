class Solution {
public:
    bool isPalindrome(string s) {
        string rs;
        for(char ch: s)
        {
            if(isalnum(ch)) rs += tolower(ch);
        }
        int n = rs.size();
        int i = 0, j = n - 1;
        while(i <= j)
        {
            if(rs[i] != rs[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};