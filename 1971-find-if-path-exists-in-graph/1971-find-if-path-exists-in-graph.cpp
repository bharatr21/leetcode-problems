class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(vector<int>& e: edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(source);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = true;
            if(x == destination) return true;
            for(int& y: adj[x]) {
                if(!vis[y]) q.push(y);
            }
        }
        return false;
    }
};