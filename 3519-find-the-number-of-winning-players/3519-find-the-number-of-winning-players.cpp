class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ct = 0;
        vector<unordered_map<int, int>> vmp(n);
        for(auto el: pick) {
            auto tmp = el;
            int x = tmp[0], y = tmp[1];
            vmp[x][y]++;
        }
        for(int i = 0; i < n; i++) {
            for(auto u: vmp[i]) {
                if(u.second > i) {
                    ct++;
                    break;
                }
            }
        }
        return ct;
    }
};