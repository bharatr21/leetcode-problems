class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int st = intervals[0][0], en = intervals[0][1];
        vector<vector<int>> res;
        res.push_back({st, en});
        for(int i = 1; i < n; i++) {
            int inst = intervals[i][0], inen = intervals[i][1];
            if(st > inen || en < inst) res.push_back({inst, inen});
            else {
                res.back()[1] = max(res.back()[1], inen);
                en = res.back()[1];
            }
        }
        return res;
    }
};