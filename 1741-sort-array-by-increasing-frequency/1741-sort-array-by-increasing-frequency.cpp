class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return ((p1.first == p2.first) ? (p1.second > p2.second) : (p1.first < p2.first));
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        vector<pair<int, int>> vp;
        for(auto el: nums) mp[el]++;
        for(auto u: mp) {
            vp.push_back({u.second, u.first});
        }
        sort(vp.begin(), vp.end(), cmp);
        for(auto u: vp) {
            for(int i = 1; i <= u.first; i++) {
                res.push_back(u.second);
            }
        }
        return res;
    }
};