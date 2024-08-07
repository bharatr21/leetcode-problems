class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return 0;
        int vstart = -1, vend = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == val && vstart == -1) {
                vstart = i;
                vend = i;
                while(i < n && nums[i] == val) {
                    i++;
                }
                vend = i;
                break;
            }
        }
        int j = vstart;
        if(vend != -1) {
            for(int i = vend; i < n; i++) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return n - (vend - vstart);
    }
};