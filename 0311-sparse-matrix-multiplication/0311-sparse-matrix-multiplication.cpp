class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), p = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < p; k++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return res;
    }
};