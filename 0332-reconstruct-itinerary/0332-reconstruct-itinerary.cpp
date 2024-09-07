class Comparator {
    public:
        unordered_map<string, int>& out;
        Comparator(unordered_map<string, int>& outdeg): out(outdeg) {};
        bool operator() (string s1, string s2) const {
            return ((out[s1] == out[s2]) ? s1 < s2 : out[s1] > out[s2]);
        }
};
class Solution {
public:
    void dfs(string src, unordered_map<string, vector<string>>& adj, vector<string>& res, set<pair<string, string>>& vis) {
        while(!adj[src].empty()) {
            auto dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, res, vis); 
        }
        res.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> adj;
        set<pair<string, string>> vis;
        unordered_map<string, int> indeg, outdeg;
        for(vector<string> v: tickets) {
            string src = v[0], dst = v[1];
            adj[src].push_back(dst);
            indeg[dst]++;
            outdeg[src]++;
        }
        for(auto it: adj) {
            sort(adj[it.first].begin(), adj[it.first].end(), greater<string>());
        }
        dfs("JFK", adj, res, vis);
        reverse(res.begin(), res.end());
        return res;
    }
};