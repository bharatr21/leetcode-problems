class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> sres;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while(j < k) {
                if(nums[j] + nums[k] == target) {
                    tmp = {nums[i], nums[j], nums[k]};
                    sort(tmp.begin(), tmp.end());
                    sres.insert(tmp);
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > target) j++;
                else k--;
            }
        }
        vector<vector<int>> res(sres.begin(), sres.end());
        return res;
    }
};