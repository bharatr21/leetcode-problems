class Solution {
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        vector<pair<int, int>> p;
        int i;
        for(int n: nums)
        {
            mp[n]++;
        }
        for(auto u: mp)
        {
            p.push_back({u.first, u.second});
        }
        sort(p.begin(), p.end(), cmp);
        for(i = 0; i < k; i++)
        {
            res.push_back(p[i].first);
        }
        return res;
    }
};