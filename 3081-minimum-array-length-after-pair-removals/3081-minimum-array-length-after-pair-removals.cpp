class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int ans = n;
        for(int i = 0, j = (n + 1) / 2; i < n / 2 && j < n; j++) {
            if(nums[i] < nums[j]) {i++; ans -= 2;}
        }
        return ans;
    }
};