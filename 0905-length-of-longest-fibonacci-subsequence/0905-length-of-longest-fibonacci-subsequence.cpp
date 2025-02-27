class Solution {
public:
    int buildFibo(int a, int b, unordered_set<int>& s, set<pair<int, int>>& vis) {
        vis.insert({a, b});
        int res = 2;
        int c = a + b;
        while(s.count(c)) {
            res++;
            vis.insert({b, c});
            a = b;
            b = c;
            c = a + b;
        }
        return ((res < 3) ? 0 : res);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), mx = 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> idxMap;
        for(int cur = 0; cur < n; cur++) idxMap[arr[cur]] = cur;
        for(int cur = 0; cur < n; cur++) {
            for(int prev = 0; prev < cur; prev++) {
                int diff = arr[cur] - arr[prev];
                int idx = -1;
                if(idxMap.count(diff)) {
                    idx = idxMap[diff]; 
                }
                if(idx >= 0 && arr[idx] < arr[prev]) {
                    dp[prev][cur] = dp[idx][prev] + 1;
                } else dp[prev][cur] = 2;
                mx = max(mx, dp[prev][cur]);
            }
        }
        return ((mx < 3) ? 0 : mx);
    }
};