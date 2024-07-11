class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i, j;
        vector<int> minJ(n, 10005);
        minJ[n-1] = 0;
        for(i = n-2; i>=0; i--)
        {
            int furthest = min(n-1, i+nums[i]);
            for(j = i; j <= furthest; j++)
            {
                minJ[i] = min(1 + minJ[j], minJ[i]);
            }
        }
        return minJ[0];
    }
};