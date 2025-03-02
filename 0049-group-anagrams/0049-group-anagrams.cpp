class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> store;
        vector<vector<string>> res;
        for(string s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            store[tmp].push_back(s);
        }
        for(auto u: store) {
            res.push_back(u.second);
        }
        return res;
    }
};