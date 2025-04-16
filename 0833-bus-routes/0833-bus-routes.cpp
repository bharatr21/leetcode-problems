class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> adj;
        int n = routes.size();
        for(int route = 0; route < n; route++) {
            for(auto stop: routes[route]) {
                adj[stop].push_back(route);
            }
        }
        queue<pair<int, int>> q;
        unordered_set<int> seen;
        if(source == target) return 0;
        for(auto route: adj[source]) {
            q.push({route, 1});
            seen.insert(route);
        }
        while(!q.empty()) {
            auto [route, busCount] = q.front();
            q.pop();
            for(int stop: routes[route]) {
                if(stop == target) return busCount;
                for(auto nextRoute: adj[stop]) {
                    if(!seen.count(nextRoute)) {
                        q.push({nextRoute, busCount + 1});
                        seen.insert(nextRoute);
                    }
                }
            }
        }
        return -1;
    }
};