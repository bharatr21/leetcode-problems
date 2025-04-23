class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        vector<pair<int, int>> p;
        int i;
        for(int n: nums)
        {
            mp[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto u: mp)
        {
            pq.push({u.second, u.first});
        }
        for(i = 0; i < k; i++)
        {
            auto [freq, el] = pq.top();
            pq.pop();
            res.push_back(el);
        }
        return res;
    }
};