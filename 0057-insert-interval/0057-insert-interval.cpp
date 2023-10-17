class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        int n = intervals.size(), i;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        if(n == 1) return res;
        for(i = 1; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if(res.back().back() < start || res.back()[0] > end)
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back().back() = max(res.back().back(), end);
            }
        }
        return res;
    }
};