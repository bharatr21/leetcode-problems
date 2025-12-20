class Solution {
public:
    long long calcProfit(vector<int>& prices, vector<int>& strategy) {
        int n = prices.size();
        long long profit = 0;
        for(int i = 0; i < n; i++) profit += strategy[i] * prices[i];
        return profit;
    }

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<int> orig = strategy;
        int n = prices.size();
        long long profit = calcProfit(prices, strategy);
        // cout << "Original Profit: " << profit << endl;
        long long maxProfit = profit;
        for(int i = 0; i < k; i++) {
            if(i < k/2) strategy[i] = 0;
            else strategy[i] = 1;
        }
        profit = calcProfit(prices, strategy);
        // cout << "1st Window Profit: " << profit << endl;
        maxProfit = max(maxProfit, profit);
        // for(int el: orig) cout << el << ' ';
        // cout << endl;
        for(int i = 1; i <= n - k; i++) {
            // cout << "Indices: " << (i - 1) << ' ' << (2 * i + k - 1) / 2 << ' ' << (i+k-1) << endl;
            strategy[i-1] = orig[i-1];
            profit += strategy[i-1] * prices[i-1];
            profit -= orig[i+k-1] * prices[i+k-1];
            strategy[i+k-1] = 1;
            profit += strategy[i+k-1] * prices[i+k-1];
            profit -= prices[(2*i+k-1)/2];
            strategy[(2*i+k-1)/2] = 0;
            // for(int el: strategy) cout << el << ' ';
            // cout << endl;
            // cout << "Profit: " << profit << endl;
            maxProfit = max(maxProfit, profit); 
        }
        return maxProfit;
    }
};