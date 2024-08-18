class Solution {
public:
    int power(vector<int>& nums, int st, int en) {
        bool mx = true;
        for(int i = st; i < en; i++) {
            if(nums[i+1] != nums[i] + 1) {
                mx = false;
                break;
            }
        }
        return ((mx) ? nums[en] : -1);
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            res.push_back(power(nums, i, j));
        }
        return res;
    }
};