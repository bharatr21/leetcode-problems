class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i;
        int min_so_far = prices[0], profit = 0;
        for(i = 0; i < n; i++)
        {
            min_so_far = min(prices[i], min_so_far);
            profit = max(profit, prices[i] - min_so_far);
        }
        return profit;
    }
};
