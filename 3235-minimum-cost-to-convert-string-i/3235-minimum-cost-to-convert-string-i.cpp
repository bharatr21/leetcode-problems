class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));
        int n = original.size(), i, j, k;
        for(i = 0; i < n; i++) {
            minCost[original[i] - 'a'][changed[i] - 'a'] = 
            min(minCost[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        for(i = 0; i < 26; i++) minCost[i][i] = 0;
        //Floyd-Warshall
        for(k = 0; k < 26; k++) {
            for(i = 0; i < 26; i++) {
                for(j = 0; j < 26; j++) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        n = source.size();
        for(i = 0; i < n; i++) {
            if(source[i] != target[i]) {
                long long finalCost = minCost[source[i] - 'a'][target[i] - 'a'];
                if(finalCost == INT_MAX) return -1;
                res += finalCost;
            }
        }
        return res;
    }
};