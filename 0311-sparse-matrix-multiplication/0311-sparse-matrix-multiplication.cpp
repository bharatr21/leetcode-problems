class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), p = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<pair<int, int>> nz1, nz2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                if(mat1[i][j]) nz1.push_back({i, j});
            }
        }
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < n; j++) {
                if(mat2[i][j]) nz2.push_back({i, j});
            }
        }
        for(pair<int, int>& p1: nz1) {
            for(pair<int, int>& p2: nz2) {
                auto& [i1, j1] = p1;
                auto& [i2, j2] = p2;
                if(j1 == i2) {
                    res[i1][j2] += mat1[i1][j1] * mat2[i2][j2];
                }
            }
        }
        return res;
    }
};