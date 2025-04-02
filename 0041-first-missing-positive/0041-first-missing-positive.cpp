class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for(int el: nums) {
            if(el > 0 && el <= n) seen.insert(el);
        }
        for(int i = 1; i <= n; i++) {
            if(!seen.count(i)) return i;
        }
        return n + 1;
    }
};