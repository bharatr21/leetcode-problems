class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastzerofoundat = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                nums[lastzerofoundat++] = nums[i];
            }
        }
        for(int i = lastzerofoundat; i < n; i++) nums[i] = 0;
    }
};