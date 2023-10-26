class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> res;
        int r = a.size(), c = a[0].size(), i, j;
        int up = 0, down = r - 1, left = 0, right = c - 1;
        while(res.size() < r * c) {
            // Right
            for(int col = left; col <= right; col++)
            {
                res.push_back(a[up][col]);
            }

            // Down
            for(int row = up + 1; row <= down; row++)
            {
                res.push_back(a[row][right]);
            }

            // Left (Different row)
            if(up != down) {
                for(int col = right - 1; col >= left; col--)
                {
                    res.push_back(a[down][col]);
                }
            }

            // Up (Different column)
            if(left != right) {
                for(int row = down - 1; row > up; row--)
                {
                    res.push_back(a[row][left]);
                }   
            }

            // Updates
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};