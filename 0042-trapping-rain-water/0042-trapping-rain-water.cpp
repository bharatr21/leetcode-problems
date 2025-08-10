class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1;
        int lmax = 0, rmax = 0;
        int tot = 0;
        while(left < right) {
            if(heights[left] < heights[right]) {
                tot += max(0, lmax - heights[left]);
                lmax = max(lmax, heights[left]);
                left++;
            } else {
                tot += max(0, rmax - heights[right]);
                rmax = max(rmax, heights[right]);
                right--;
            }
        }
        return tot;
    }
};