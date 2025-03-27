class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), mx = -1, cand = -1;
        unordered_map<int, int> fre;
        for(int num: nums) {
            fre[num]++;
            if(mx < fre[num]) {
                mx = fre[num];
                cand = num;
            }
        }
        int cur_freq = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == cand) cur_freq++;
            if((cur_freq * 2) > i + 1 && (fre[cand] - cur_freq) * 2 > n - i - 1) return i;
        }
        return -1;
    }
};