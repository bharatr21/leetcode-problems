class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int res = 0;
        vector<string> suffixes(n);
        for(int i = 0; i < n; i++) {
            suffixes[i] = s.substr(i);
        }
        sort(suffixes.begin(), suffixes.end());
        for(int i = 1; i < n; i++) {
            int j = 0;
            while(j < min(suffixes[i].size(), suffixes[i - 1].size()) && 
            suffixes[i][j] == suffixes[i-1][j]) {j++;}
            res = max(res, j);
        }
        return res;
    }
};