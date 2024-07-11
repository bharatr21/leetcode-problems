class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 0), prev(n, 0);
        int i, j;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(j == 0) {cur[j] = 1; continue;}
                int down = prev[j];
                int left = cur[j-1];
                cur[j] = down + left;

            }
            prev = cur;
        }
        return cur[n-1];
    }
};