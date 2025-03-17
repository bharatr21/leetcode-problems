class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> fre(mx + 1, 0);
        for(int el: nums) fre[el]++;
        for(int el: fre) {
            if(el % 2) return false;
        }
        return true;
    }
};