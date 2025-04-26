class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int st = intervals[0][0], en = intervals[0][1];
        for(int i = 1; i < n; i++) {
            int inst = intervals[i][0], inen = intervals[i][1];
            if(inst > en || inen < st) {
                res.push_back({st, en});
                st = inst;
                en = inen;
            }
            st = min(st, inst);
            en = max(en, inen);
        }
        res.push_back({st, en});
        return res;
    }
};