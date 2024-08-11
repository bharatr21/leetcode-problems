class Solution {
public:
    int subCount(int node, vector<vector<int>>& adj, vector<vector<int>>& children, int parent, vector<int>& counts) {
        int res = 1;
        for(int nbr: adj[node]) {
            if(nbr != parent) {
                children[node].push_back(nbr);
                if(counts[nbr] != -1) res += counts[nbr];
                else res += subCount(nbr, adj, children, node, counts);
            }
        }
        return (counts[node] = res);
    }

    bool isGood(int node, vector<vector<int>>& children, vector<int>& counts) {
        int ht = -1, tmp = -1;
        for(int child: children[node]) {
            tmp = counts[child];
            if(ht == -1) ht = tmp;
            else if(ht != -1 && ht != tmp) return false;
        }
        return true;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n), children(n);
        vector<int> counts(n, -1);
        int res = 0;
        for(auto v: edges) {
            int a = v[0], b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        subCount(0, adj, children, -1, counts);
        for(int i = 0; i < n; i++) {
            if(isGood(i, children, counts)) {
                res++;
            }
        }
        return res;
    }
};