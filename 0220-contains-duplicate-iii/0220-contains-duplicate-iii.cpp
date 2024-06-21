class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int, int>> vp;
        set<int> s;
        int n = nums.size(), i;
        for(i = 0; i < n; i++)
        {
            auto it = s.lower_bound(nums[i]);
            if(it != s.end() && *it <= nums[i] + valueDiff) return true;
            if(it != s.begin())
            {
                auto it2 = prev(it);
                if(*it2 >= nums[i] - valueDiff) return true;
            }
            s.insert(nums[i]);
            if(s.size() > indexDiff) s.erase(nums[i - indexDiff]);
        }
        return false;
    }
};