class Solution {
public:
    bool isPalindrome(string s) {
        string cls;
        for(char ch: s)
        {
            if(isalnum(ch)) cls += tolower(ch);
        }
        int n = cls.size();
        int i = 0, j = n - 1;
        while(i <= j)
        {
            if(cls[i] != cls[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
