class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long int> sizes(n, 0);
        long int res = 0;
        int i;
        for(vector<int> v: roads) {
            int a = v[0], b = v[1];
            sizes[a]++;
            sizes[b]++;
        }
        sort(sizes.begin(), sizes.end(), greater<int>());
        for(i = 0; i < n; i++) {
            res += sizes[i] * (n - i);
        }
        return res;
    }
};