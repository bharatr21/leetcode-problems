class Solution {
public:
    double dfs(string s, string d, double cur, unordered_set<string>& vis, unordered_map<string, vector<pair<string, double>>>& adj) {
        if(s == d) return cur;
        vis.insert(s);
        for(auto [ne, val]: adj[s]) {
            if(ne == d) return cur * val;
            if(!vis.count(ne)) {
                double ans = dfs(ne, d, cur * val, vis, adj);
                if(ans != -1.0) return ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_set<string> v;
        for(int i = 0; i < n; i++) {
            string s = equations[i][0], d = equations[i][1];
            double val = values[i];
            adj[s].push_back({d, val});
            adj[d].push_back({s, 1.0 / val});
            v.insert(s);
            v.insert(d);
        }
        // for(auto el: adj) {
        //     cout << el.first << endl;
        //     for(auto u: el.second) cout << u.first << ' ' << u.second << endl;
        // }
        vector<double> res;
        for(vector<string> q: queries) {
            string s = q[0], d = q[1];
            if(!v.count(s) || !v.count(d)) {res.push_back(-1.0); continue;}
            else if(s == d) {res.push_back(1.0); continue;}
            unordered_set<string> vis;
            double cur = 1.0;
            res.push_back(dfs(s, d, cur, vis, adj));
        }
        return res;
    }
};