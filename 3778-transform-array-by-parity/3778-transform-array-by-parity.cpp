class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {

       int l1 = 0;
       int n = nums.size();
       for(int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
            if(!nums[i]) swap(nums[l1++], nums[i]);
       }
       return nums;
    }
};