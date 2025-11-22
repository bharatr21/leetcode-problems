class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for(int el: nums) res += ((el % 3) ? 1 : 0);
        return res;
    }
};