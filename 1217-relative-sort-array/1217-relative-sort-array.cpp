class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return ((p1.second == p2.second) ? (p1.first < p2.first): (p1.second < p2.second));
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int n = arr1.size(), m = arr2.size(), i;
        unordered_map<int, int> mp;
        for(i = 0; i < m; i++) mp[arr2[i]] = i;
        vector<pair<int, int>> vp;
        for(i = 0; i < n; i++)
        {
            if(mp.find(arr1[i]) == mp.end()) vp.push_back({arr1[i], n+1});
            else vp.push_back({arr1[i], mp[arr1[i]]});
        }
        sort(vp.begin(), vp.end(), cmp);
        for(i = 0; i < n; i++) res.push_back(vp[i].first);
        return res;
    }
};