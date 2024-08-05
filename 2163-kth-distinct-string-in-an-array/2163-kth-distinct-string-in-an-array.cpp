class Solution {
public:
    static bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
        return (p1.second < p2.second);
    }
    string kthDistinct(vector<string>& arr, int k) {
        string res;
        int n = arr.size(), ct = 0;
        set<string> eraseKey;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            if(mp.count(arr[i])) mp[arr[i]] = n + 1;
            else mp[arr[i]] = i;
        }
        for(auto& u: mp) {
            if(u.second > n) eraseKey.insert(u.first);
        }
        for(string el: eraseKey) {
            mp.erase(el);
        }
        vector<pair<string, int>> vp(mp.begin(), mp.end());
        if(vp.size() < k) return res;
        sort(vp.begin(), vp.end(), cmp);
        return vp[k-1].first;
    }
};