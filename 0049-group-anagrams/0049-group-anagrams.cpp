class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        vector<vector<string>> res;
        for(string st: strs) {
            string key = st;
            sort(key.begin(), key.end());
            ump[key].push_back(st);
        }
        for(auto el: ump) {
            res.push_back(el.second);
        }
        return res;
    }
};