class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = -1, INF = 1000001;
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> ans(n+1, INF);
        for(vector<int>& e: times) {
            int src = e[0], dst = e[1], wt = e[2];
            adj[src].push_back({wt, dst});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        ans[k] = 0;
        while(!pq.empty()) {
            auto [w, src] = pq.top();
            pq.pop();
            if(w > ans[src]) continue;
            for(pair<int, int>& e: adj[src]) {
                auto [wt, dst] = e;
                if(ans[dst] > ans[src] + wt) {
                    ans[dst] = ans[src] + wt;
                    pq.push({ans[dst], dst});
                }
            }
        }
        res = *max_element(ans.begin() + 1, ans.end());
        return (res == INF) ? -1 : res;
    }
};