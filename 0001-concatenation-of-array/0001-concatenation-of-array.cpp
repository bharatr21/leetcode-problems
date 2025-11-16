class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.begin(), nums.end());
        for(int el: nums) res.push_back(el);
        return res;
    }
};