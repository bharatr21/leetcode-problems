class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        string tmp;
        for(string str: strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }
        for(auto u: mp)
        {
            res.push_back(u.second);
        }
        return res;
    }
};