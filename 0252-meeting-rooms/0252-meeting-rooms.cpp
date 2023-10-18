class Solution {
public:
    bool hasOverlap(vector<int>& a, vector<int>& b) {
        return !(a[1] <= b[0]);
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size(), i;
        if(n <= 1) return true;
        sort(intervals.begin(), intervals.end());
        for(i = 1; i < n; i++)
        {
            if(hasOverlap(intervals[i-1], intervals[i])) return false;   
        }
        return true;
    }
};