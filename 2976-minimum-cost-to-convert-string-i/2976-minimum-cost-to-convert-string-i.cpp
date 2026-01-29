class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        typedef long long ll;
        vector<vector<ll>> weights(26, vector<ll>(26, INT_MAX));
        for(int i = 0; i < 26; i++) weights[i][i] = 0;
        int n = original.size();
        for(int i = 0; i < n; i++) {
            weights[original[i] - 'a'][changed[i] - 'a'] = min(weights[original[i] - 'a'][changed[i] - 'a'], cost[i] * 1LL);
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
                }
            }
        }
        int m = source.size();
        ll res = 0;
        for(int i = 0; i < m; i++) {
            if(weights[source[i] - 'a'][target[i] - 'a'] >= INT_MAX) return -1;
            else res += weights[source[i] - 'a'][target[i] - 'a'];
        }
        return res;
    }
};