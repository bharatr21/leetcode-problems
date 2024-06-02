class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> mp;
        vector<int> res;
        int n = arrays.size();
        for(vector<int> array: arrays)
        {
            for(int el: array)
            {
                mp[el]++;
            }
        }
        for(auto u: mp)
        {
            if(u.second == n) res.push_back(u.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};