class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int idx1 = -n-1, idx2 = -2*n-1, i = 0, res = n + 2;
        for(string word: wordsDict) {
            if(word == word1) idx1 = i;
            else if(word == word2) idx2 = i;
            i++;
            res = min(res, abs(idx1 - idx2));
        }
        return res;
    }
};