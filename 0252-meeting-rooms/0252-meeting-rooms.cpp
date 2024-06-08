class Solution {
public:
    bool isOverlap(int st, int en, vector<int>& interval) {
        int ist = interval[0], ien = interval[1];
        return !(st > ien || en < ist || st == ien || ist == en);
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int st, en, ist, ien;
        int n = intervals.size(), i;
        if(n <= 1) return true;
        sort(intervals.begin(), intervals.end());
        st = intervals[0][0];
        en = intervals[0][1];
        for(i = 1; i < n; i++)
        {
            if(isOverlap(st, en, intervals[i])) return false;
            st = intervals[i][0], en = intervals[i][1];
        }
        return true;
    }
};