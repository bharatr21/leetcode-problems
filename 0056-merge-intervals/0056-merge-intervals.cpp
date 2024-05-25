class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), i;
        if(n == 0) return res;
        if(n == 1) return {intervals};
        res.push_back(intervals[0]);
        for(i = 1; i < n; i++)
        {
            int st = res.back()[0], en = res.back()[1]; 
            int a = intervals[i][0], b = intervals[i][1];
            if(a > en || b < st) res.push_back(intervals[i]);
            else res.back().back() = max(b, res.back().back());
        }
        return res;
    }
};