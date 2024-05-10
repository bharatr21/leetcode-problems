class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2)
    {
        return (1.0 * p1.first) / p1.second < (1.0 * p2.first) / p2.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> vp;
        int n = arr.size(), i, j;
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                vp.push_back({arr[i], arr[j]});
            }
        }
        sort(vp.begin(), vp.end(), cmp);
        return {vp[k-1].first, vp[k-1].second};
    }
};