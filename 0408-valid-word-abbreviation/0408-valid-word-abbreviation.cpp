class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, m = word.size(), n = abbr.size();
        while(i < m && j < n) {
            int d = 0;
            while(isdigit(abbr[j])) {
                if(!d && abbr[j] == '0') return false;
                d = d * 10 + (abbr[j] - '0');
                j++;
            }
            if(!d) {
                if(word[i] != abbr[j]) return false;
                i++;
                j++;
            } else {
                i += d;
            }
        }   
        return ((i == m) && (j == n));
    }
};