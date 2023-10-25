class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), i, j;
        bool firstRow = false, firstCol = false;
        for(i = 0; i < m; i++)
        {
            if(a[i][0] == 0)
            {
                firstRow = true; 
                break;
            }
        }
        for(j = 0; j < n; j++)
        {
            if(a[0][j] == 0)
            {
                firstCol = true; 
                break;
            }
        }
        for(i = 0; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(a[i][j] == 0)
                {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        for(i = 1; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(a[i][j])
                {
                    if((a[i][0] == 0) || (a[0][j] == 0)) a[i][j] = 0;
                }
            }
        }
        if(firstRow)
        {
            for(i = 0; i < m; i++) a[i][0] = 0;
        }
        if(firstCol)
        {
            for(j = 0; j < n; j++) a[0][j] = 0;
        }
    }
};