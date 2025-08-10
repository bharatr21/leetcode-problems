class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anags;
        vector<vector<string>> res;
        for(string st: strs) {
            string key = st;
            sort(key.begin(), key.end());
            anags[key].push_back(st);
        }
        for(auto u: anags) {
            res.push_back(u.second);
        }
        return res;
    }
};