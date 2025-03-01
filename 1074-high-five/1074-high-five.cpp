class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> store;
        for(vector<int> item: items) {
            int id = item[0], score = item[1];
            store[id].push(score);
        }
        vector<vector<int>> res;
        for(auto u: store) {
            int score = 0;
            for(int i = 0; i < 5; i++) {
                score += u.second.top();
                u.second.pop();
            }
            score /= 5;
            res.push_back({u.first, score});
        }
        return res;
    }
};