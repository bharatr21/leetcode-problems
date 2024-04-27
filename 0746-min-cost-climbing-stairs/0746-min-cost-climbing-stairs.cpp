class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), i;
        vector<int> res(n+1, 0);
        if(n <= 2) return *min_element(cost.begin(), cost.end());
        res[0] = cost[0];
        res[1] = cost[1];
        for(i = 2; i < n; i++)
        {
            res[i] = cost[i] + min(res[i-1], res[i-2]);
        }
        return min(res[n-1], res[n-2]);
    }
};