class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size(), i, j;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = books[0][1];
        for(i = 1; i <= n; i++) {
            int remainingWidth = shelfWidth - books[i-1][0];
            int maxHeight = books[i-1][1];
            dp[i] = dp[i-1] + maxHeight;
            j = i - 1;
            while(j > 0 && remainingWidth >= books[j-1][0]) {
                remainingWidth -= books[j-1][0];
                maxHeight = max(maxHeight, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + maxHeight);
                j--;
            }
        }
        return dp[n];
    }
};