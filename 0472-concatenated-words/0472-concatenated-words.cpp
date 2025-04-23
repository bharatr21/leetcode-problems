class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> seen;
        sort(words.begin(), words.end(), [](string& s1, string& s2) {return s1.size() < s2.size();});
        for(auto& word: words) {
            int n = word.size();
            vector<bool> dp(n+1, false);
            dp[0] = true;
            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < i; j++) {
                    if(dp[j] && seen.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if(dp[n]) res.push_back(word);
            seen.insert(word);
        }
        return res;
    }
};