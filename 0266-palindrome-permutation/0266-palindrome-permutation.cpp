class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size(), odd = 0;
        vector<char> fre(26, 0);
        for(char ch: s) fre[ch - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(fre[i] % 2) odd++;
        }
        return ((odd == 1 && n % 2) || (odd == 0));
    }
};