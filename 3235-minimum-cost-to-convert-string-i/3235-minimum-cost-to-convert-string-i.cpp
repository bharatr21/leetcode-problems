class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        vector<vector<int>> adj(26, vector<int>(26, 10000000));
        int n = original.size(), i;
        for(i = 0; i < n; i++) {
            adj[original[i] - 'a'][changed[i] - 'a'] = 
            min(adj[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        vector<vector<long long>> minPathCosts;
        for(i = 0; i < 26; i++) {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
            greater<pair<long long, int>>> pq;
            vector<long long> minCosts(26, -1);
            minCosts[i] = 0;
            pq.push({0, i});
            while(!pq.empty()) {
                auto [curCost, curChar] = pq.top();
                pq.pop();
                // if(minCosts[curChar] != -1 && minCosts[curChar] < curCost) continue; 
                //Why? Duplicates in Priority Queue?
                for(auto adjChar = 0; adjChar < adj[curChar].size(); adjChar++) {
                    if(adj[curChar][adjChar] == 10000000) continue;
                    long long newCost = curCost + adj[curChar][adjChar];
                    if(minCosts[adjChar] == -1 || newCost < minCosts[adjChar]) {
                        minCosts[adjChar] = newCost;
                        pq.push({newCost, adjChar});
                    }
                }
            }
            minPathCosts.push_back(minCosts);
        }
        n = source.size();
        for(i = 0; i < n; i++) {
            if(source[i] != target[i]) {
                long long finalCost = minPathCosts[source[i] - 'a'][target[i] - 'a'];
                if(finalCost == -1) return -1;
                res += finalCost;
            }
        }
        return res;
    }
};