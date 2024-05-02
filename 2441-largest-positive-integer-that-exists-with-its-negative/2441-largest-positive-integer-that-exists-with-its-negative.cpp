class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int st = 0, en = n - 1;
        while(st < en)
        {
            if(nums[st] + nums[en] == 0) return nums[en];
            else if(nums[st] + nums[en] < 0) st++;
            else en--;
        }
        return -1;
    }
};