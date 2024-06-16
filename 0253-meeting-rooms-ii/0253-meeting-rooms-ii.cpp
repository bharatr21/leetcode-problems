class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        int n = intervals.size(), req = 0, mx = 0, i, j;
        for(i = 0; i < n; i++)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        i = 0;
        j = 0;
        while(i < n && j < n)
        {
            if(starts[i] < ends[j])
            {
                i++;
                req++;
                mx = max(mx, req);
            }
            else
            {
                j++;
                req--;
            }
        }
        return mx;
    }
};