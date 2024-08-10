class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int st = 0, k = 1;
        for(int i = 0; i < n; i++) {
            if(i >= 1 && nums[i] == nums[st]) continue;
            else if(i >= 1) {
                if(st < n - 1) swap(nums[i], nums[st+1]);
                st++;
                k++;
            }
        }
        return k;
    }
};