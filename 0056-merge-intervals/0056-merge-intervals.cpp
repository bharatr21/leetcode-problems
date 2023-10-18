class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size(), i;
        if(n <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(i = 1; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if(res.back().back() < start || res.back()[0] > end)
            {
                res.push_back(intervals[i]);
            }
            else res.back().back() = max(res.back().back(), end);
        }
        return res;
    }
};