class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i, j, res = 0, sum = 0;
        for(i = 0; i < n; i++)
        {
            sum = 0;
            for(j = i; j < n; j++)
            {
                sum += nums[j];
                if(sum == k) {res++;}
            }
        }
        return res;
    }
};