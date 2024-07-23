class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int start = nums[0], beg = 1, last = n - 1;
        while(beg <= last) {
            int mid = beg + (last - beg) / 2;
            if(nums[mid] > start) beg = mid + 1;
            else if(nums[mid] < start) {
                if(mid >= 1 && nums[mid] < nums[mid - 1]) return nums[mid];
                else last = mid - 1;
            }
        }
        return start;
    }
};