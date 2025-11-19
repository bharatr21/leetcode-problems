class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st(nums.begin(), nums.end());
        int tmp = original;
        while(st.count(tmp)) {
            tmp <<= 1;
        }
        return tmp;
    }
};