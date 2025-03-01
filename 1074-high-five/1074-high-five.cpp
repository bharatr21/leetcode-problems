class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> store;
        for(vector<int> item: items) {
            store[item[0]].push_back(item[1]);
        }
        vector<vector<int>> res;
        for(auto u: store) {
            sort(u.second.begin(), u.second.end(), greater<int>());
            int score = 0;
            for(int i = 0; i < 5; i++) {
                score += u.second[i];
            }
            score /= 5;
            res.push_back({u.first, score});
            sort(res.begin(), res.end());
        }
        return res;
    }
};