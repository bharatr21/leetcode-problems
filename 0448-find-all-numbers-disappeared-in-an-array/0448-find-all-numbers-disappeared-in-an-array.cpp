class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        vector<int> res;
        for(int el: nums) s.insert(el);
        for(int i = 1; i <= n; i++) {
            if(!s.count(i)) res.push_back(i);
        }
        return res;
    }
};