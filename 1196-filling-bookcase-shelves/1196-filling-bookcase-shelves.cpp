class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& books, int shelfWidth, int idx, int remainingWidth, int maxHeight) {
        int n = books.size(), res;
        auto currentBook = books[idx];
        int maxHeightUpdate = max(maxHeight, currentBook[1]);
        if(idx == n - 1) {
            return ((remainingWidth >= currentBook[0]) ? maxHeightUpdate : maxHeight + currentBook[1]);
        }
        else if(dp[idx][remainingWidth] != -1) return dp[idx][remainingWidth]; 
        // Put book in new shelf
        int keep = maxHeight + solve(dp, books, shelfWidth, idx + 1, shelfWidth - currentBook[0], currentBook[1]);
        res = keep;
        if(remainingWidth >= currentBook[0]) {
            //Put book in existing shelf
            int not_keep = solve(dp, books, shelfWidth, idx + 1, remainingWidth - currentBook[0], maxHeightUpdate);
            res = min(res, not_keep);
        }
        return (dp[idx][remainingWidth] = res);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));
        return solve(dp, books, shelfWidth, 0, shelfWidth, 0);
    }
};