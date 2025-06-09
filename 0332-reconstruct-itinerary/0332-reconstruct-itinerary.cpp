class Solution {
public:
    void dfs(string src, unordered_map<string, vector<string>>& adj, vector<string>& res) {
        while(!adj[src].empty()) {
            auto dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res);
        }
        res.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> adj;
        int n = tickets.size();
        for(vector<string>& e: tickets) {
            string src = e[0], dst = e[1];
            adj[src].push_back(dst);
        }
        for(auto item: adj)
        sort(adj[item.first].begin(), adj[item.first].end(), greater<string>());
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end());
        return res;
    }
};