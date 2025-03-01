class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        int lh = height[0], rh = height[n-1];
        int i = 0, j = n - 1;
        while(i <= j) {
            if(lh <= rh) {
                res += max(0, (lh - height[i]));
                lh = max(lh, height[i]);
                i++;
            } else {
                res += max(0, (rh - height[j]));
                rh = max(rh, height[j]);
                j--;
            }
        }
        return res;
    }
};