class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int rowIdx, colIdx;
        int beg = 0, end = m - 1, left = 0, right = n - 1;
        while(beg < end)
        {
            int mid = beg + (end - beg) / 2;
            if(target > matrix[mid][n-1]) beg = mid + 1;
            else end = mid;
        }
        if(beg == m) return false;
        if(matrix[beg][n-1] == target) return true;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(target == matrix[beg][mid]) return true;
            if(target > matrix[beg][mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
}; 