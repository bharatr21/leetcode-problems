class Solution {
public:
    int findPivot(vector<int>& a) {
        int n = a.size();
        int beg = 0, last = n - 1;
        while(beg <= last)
        {
            int mid = beg + (last - beg) / 2;
            if(a[mid] > a[n - 1]) beg = mid + 1;
            else last = mid - 1;
        }
        return beg;
    }
    int binsearch(vector<int>& a, int start, int end, int target) {
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(a[mid] == target) return mid;
            if(a[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size(), i, left;
        if(n == 1) return ((nums[0] == target) ? 0: -1);
        left = findPivot(nums);
        cout << left << endl;
        int idx = binsearch(nums, 0, left - 1, target);
        if(idx != -1) return idx;
        return binsearch(nums, left, n - 1, target);
    }
};