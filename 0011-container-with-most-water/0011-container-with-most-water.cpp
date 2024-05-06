class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), mx = 0;
        int left = 0, right = n - 1;
        while(left <= right)
        {
            mx = max(mx, min(height[left], height[right]) * (right - left));
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return mx;
    }
};