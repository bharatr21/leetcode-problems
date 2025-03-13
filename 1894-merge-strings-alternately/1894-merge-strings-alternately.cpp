class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size(), i;
        string res;
        for(i = 0; i < min(m, n); i++)
        {
            res += word1[i];
            res += word2[i];
        }
        while(i < m)
        {
            res += word1[i];
            i++;
        }
        while(i < n)
        {
            res += word2[i];
            i++;
        }
        return res;
    }
};