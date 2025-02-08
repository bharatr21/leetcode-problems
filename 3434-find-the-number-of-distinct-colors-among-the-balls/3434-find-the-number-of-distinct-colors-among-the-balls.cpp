class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        map<int, int> freq;
        unordered_map<int, int> balls;
        int n = queries.size();
        for(int i = 0; i < n; i++) {
            int x = queries[i][0], y = queries[i][1];
            if(balls.count(x)) {
                if(--freq[balls[x]] == 0) {
                    freq.erase(balls[x]);
                    balls.erase(x);
                }
            }
            balls[x] = y;
            freq[y]++;
            res.push_back(freq.size());
        }
        return res;
    }
};