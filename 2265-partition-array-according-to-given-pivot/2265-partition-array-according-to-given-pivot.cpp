class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left, right, mid, res;
        for(int el: nums) {
            if(el < pivot) left.push_back(el);
            else if(el > pivot) right.push_back(el);
            else mid.push_back(el);
        }
        res.reserve(n);
        copy(left.begin(), left.end(), back_inserter(res));
        copy(mid.begin(), mid.end(), back_inserter(res));
        copy(right.begin(), right.end(), back_inserter(res));
        return res;
    }
};