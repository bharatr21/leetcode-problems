class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1, mx = -1;
        while(left < right) {
            mx = max(mx, min(heights[left], heights[right]) * (right - left));
            (heights[left] < heights[right]) ? left++ : right--;
        }
        return mx;
    }
};