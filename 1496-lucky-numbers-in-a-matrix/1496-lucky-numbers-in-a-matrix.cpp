class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i, j;
        vector<int> minRow(m, 100001), maxCol(n, 0), res;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        sort(minRow.begin(), minRow.end());
        sort(maxCol.begin(), maxCol.end());
        for(i = 0, j = 0; i < m && j < n;) {
            if(minRow[i] == maxCol[j]) {
                res.push_back(minRow[i]);
                i++;
                j++;
            }
            else if(minRow[i] < maxCol[j]) i++;
            else j++;
        }
        return res;
    }
};