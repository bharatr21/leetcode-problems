class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        int n = intervals.size();
        for(int i = 1; i < n; i++) {
            int st = res.back()[0], en = res.back()[1];
            int a = intervals[i][0], b = intervals[i][1];
            if(b < st || a > en) res.push_back({a, b});
            else {
                res.back()[0] = min(a, st);
                res.back().back() = max(b, en);
            }
        }
        return res;
    }
};
