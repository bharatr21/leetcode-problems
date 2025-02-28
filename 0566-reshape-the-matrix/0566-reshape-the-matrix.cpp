class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c, -1001));
        int k = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[k / c][k % c] = mat[i][j];
                k++;
            }
        }
        return res;
    }
};