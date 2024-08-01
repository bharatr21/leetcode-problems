class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, last = n - 1;
        while(beg < last) {
            int mid = beg + (last - beg) / 2;
            if(nums[mid] > nums[mid + 1]) last = mid;
            else beg = mid + 1;
        }
        return beg;
    }
};