class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> probs(n, 0.0);
        int m = edges.size();
        probs[start_node] = 1.0;
        for(int i = 0; i < n - 1; i++) {
            bool hasUpdate = false;
            for(int j = 0; j < m; j++) {
                int u = edges[j][0], v = edges[j][1];
                double pathProb = succProb[j];
                if(probs[u] * pathProb > probs[v]) {
                    probs[v] = probs[u] * pathProb;
                    hasUpdate = true;
                }
                if(probs[v] * pathProb > probs[u]) {
                    probs[u] = probs[v] * pathProb;
                    hasUpdate = true;
                }
            }
            if(!hasUpdate) break;
        }
        return probs[end_node];
    }
};