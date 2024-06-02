class Solution {
public:
    bool isOverlap(vector<int>& p1, vector<int>& p2) {
        return ((p1[0] < p2[1] && p1[0] > p2[0]) || (p2[0] < p1[1] && p2[0] > p1[0]) || (p1[0] == p2[0]));
    }
    int shorterEnd(vector<int>& p1, vector<int>& p2, int i, int j) {
        return (p1[1] < p2[1] ? i : j);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), i = 1, j = 0, res = 0;
        while(i < n && j < n)
        {
            if(isOverlap(intervals[i], intervals[j])) {res++; j = shorterEnd(intervals[i], intervals[j], i, j);}
            else j = i; 
            i++;
        }
        return res;
    }
};