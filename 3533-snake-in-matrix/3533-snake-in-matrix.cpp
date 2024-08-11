class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = (i * n + j);
            }
        }
        unordered_map<string, pair<int, int>> dirs = { 
            {"RIGHT", {0, 1}},
            {"LEFT", {0, -1}},
            {"DOWN", {1, 0}},
            {"UP", {-1, 0}}
        };
        int r = 0, c = 0, nr = 0, nc = 0;
        for(auto command: commands) {
            nr = r + dirs[command].first;
            nc = c + dirs[command].second;
            r = nr;
            c = nc;
        }
        return mat[r][c];
    }
};