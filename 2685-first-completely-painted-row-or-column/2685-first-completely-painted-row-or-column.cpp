class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowf(m, 0), colf(n, 0);
        unordered_map<int, pair<int, int>> loc;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                loc[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0; i < m * n; i++) {
            auto [row, col] = loc[arr[i]];
            rowf[row]++;
            colf[col]++;
            if(rowf[row] == n || colf[col] == m) return i;
        }
        return -1;
    }
};