class Solution {
public:
    bool isValid(int x, int y, int m, int n) {return (x >= 0 && x < m && y >= 0 && y < n);}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pvis(m, vector<bool>(n, false)), avis(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> pq, aq;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    pvis[i][j] = true;
                    pq.push({i, j});
                }
                if(i == m - 1 || j == n - 1) {
                    avis[i][j] = true;
                    aq.push({i, j});
                }
            }
        }

        while(!pq.empty()) {
            auto [r, c] = pq.front();
            pvis[r][c] = true;
            pq.pop();
            for(int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = r + dr, nc = c + dc;
            if(isValid(nr, nc, m, n) && !pvis[nr][nc] && heights[nr][nc] >= heights[r][c]) {

                    pq.push({nr, nc});
                }
            }
        }

        while(!aq.empty()) {
            auto [r, c] = aq.front();
            avis[r][c] = true;
            aq.pop();
            for(int i = 0; i < 4; i++) {
                auto [dr, dc] = dirs[i];
                int nr = r + dr, nc = c + dc;
            if(isValid(nr, nc, m, n) && !avis[nr][nc] && heights[nr][nc] >= heights[r][c]) {

                    aq.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pvis[i][j] && avis[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};