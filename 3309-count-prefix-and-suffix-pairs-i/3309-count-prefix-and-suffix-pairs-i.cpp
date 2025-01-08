class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        for(int i = 0; i < m; i++) {
            if(s1[i] != s2[i]) return false;
        }
        for(int i= m - 1, j = n - 1; i >= 0; i--, j--) {
            if(s1[i] != s2[j]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])) res++;
            }
        }
        return res;
    }
};