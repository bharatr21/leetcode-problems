class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> freq;
        int n = wall.size(), mx = 0;
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                mx = max(mx, ++freq[sum]);
            }
        }
        return n - mx;
    }
};