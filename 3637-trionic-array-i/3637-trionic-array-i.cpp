class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 1;
        if(n <= 3) return false;
        bool p = 0, q = 0;
        while(i < n) {
            if(nums[i] == nums[i-1]) return false;
            while(i < n && nums[i] > nums[i-1]) {
                if(p && !q) q = i - 1; 
                i++;
            }
            while(i < n && nums[i] < nums[i-1]) {
                if(!p) p = i - 1;
                i++;
            }
            cout << p << ' ' << q << endl;
        }
        return (p > 0 && q > 0 && p < n - 1 && q < n - 1);
    }
};