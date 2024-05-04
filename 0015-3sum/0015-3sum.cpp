class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        set<vector<int>> s;
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            int target = -nums[i];
            j = i + 1, k = n - 1;
            while(j < k && j < n && k >= 0)
            {
                if(nums[j] + nums[k] == target)
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    if(s.find(v) == s.end()) {res.push_back(v); s.insert(v);}
                    j++;
                }
                else if(nums[j] + nums[k] > target) k--;
                else j++;
            }
        }
        return res;
    }
};