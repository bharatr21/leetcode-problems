class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i;
        int lmax = 0, lmin = 10001;
        for(i = 0; i < n; i++)
        {
            lmin = min(lmin, prices[i]);
            lmax = max(lmax, prices[i] - lmin);
        }
        return lmax;
    }
};