class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> data1d;
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c, -1001));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                data1d.push_back(mat[i][j]);
            }
        }
        int k = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res[i][j] = data1d[k++];
            }
        }
        return res;
    }
};