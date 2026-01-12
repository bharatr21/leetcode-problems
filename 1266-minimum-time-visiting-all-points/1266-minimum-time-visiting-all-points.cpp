class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> ref = points[0];
        int res = 0;
        for(int i = 1; i < n; i++) {
            int dx = abs(points[i][0] - ref[0]), dy = abs(points[i][1] - ref[1]);
            res += max(dx, dy);
            ref = points[i];
        }
        return res;
    }
};