class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i, j;
        vector<bool> canReach(n, false);
        canReach[n - 1] = true;
        for(i = n - 2; i >= 0; i--) {
            int furthest = min(n - 1, i + nums[i]);
            for(j = i + 1; j <= furthest; j++) {
                if(canReach[j]) {
                    canReach[i] = true;
                    break;
                }
            }
        }
        return canReach[0];
    }
};