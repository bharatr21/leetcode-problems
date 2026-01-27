class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(vector<int>& e: edges) {
            int a = e[0], b = e[1], w = e[2];
            adj[a].push_back({w, b});
            adj[b].push_back({2*w, a});
        }
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [w, src] = pq.top();
            pq.pop();
            if(src == n - 1) return w;

            for(auto& [cost, dst]: adj[src]) {
                if(w + cost < dist[dst]) {
                    dist[dst] = w + cost;
                    pq.push({dist[dst], dst});
                }
            }
        }
        return -1;
    }
};