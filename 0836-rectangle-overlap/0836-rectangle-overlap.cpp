class Solution {
public:
    bool intersect(int x1, int x2, int x3, int x4) {
        return min(x2, x4) > max(x1, x3);
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        if(x1 == x2 || y1 == y2 || x3 == x4 || y3 == y4) return false;
        bool xOverlap = intersect(x1, x2, x3, x4);
        bool yOverlap = intersect(y1, y2, y3, y4);
        return xOverlap && yOverlap;
    }
};