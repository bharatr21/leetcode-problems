class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, n = nums.size();
        bool vis = false;
        int cur = nums[0];
        while(i < n) {
            if(nums[i] == cur) {
                if(vis) i++;
                if(!vis) {
                    vis = true;
                    nums[j] = nums[i];
                    j++; i++;
                }
            } else {
                cur = nums[i];
                nums[j] = nums[i];
                vis = false;
                j++; i++;
            }
        }
        return j;
    }
};