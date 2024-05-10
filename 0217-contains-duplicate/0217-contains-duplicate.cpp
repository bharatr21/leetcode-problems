class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        for(int n: nums)
        {
            if(seen.find(n) != seen.end()) return true;
            seen.insert(n);
        }
        return false;
    }
};