class Solution {
public:
    double area(vector<int> points1, vector<int> points2, vector<int> points3) {
        int x1 = points1[0], y1 = points1[1];
        int x2 = points2[0], y2 = points2[1];
        int x3 = points3[0], y3 = points3[1];
        return 0.5 *
               abs(x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0.0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
};