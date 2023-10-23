class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), i, j;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void switchit(vector<vector<int>>& matrix) {
        int n = matrix.size(), i, j;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        switchit(matrix);
    }
};