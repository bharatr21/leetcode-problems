class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> cur(amount+1, 0), next(amount+1, 0);
        for(int i = 1; i <= amount; i++) next[i] = 0;
        next[0] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                if(j < coins[i]) cur[j] = next[j];
                else cur[j] = cur[j - coins[i]] + next[j];
            }
            next = cur;
        }
        return cur[amount];
    }
};