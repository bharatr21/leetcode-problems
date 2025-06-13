class Solution {
public:
    int countPairs(vector<int>& nums, int threshold)
    {
        int n = nums.size(), i = 0;
        int count = 0;
        while(i < n - 1)
        {
            if((nums[i+1] - nums[i]) <= threshold)
            {
                count++;
                i++;
            }
            i++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(n <= 1 || p == 0) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0];
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(countPairs(nums, mid) < p) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};