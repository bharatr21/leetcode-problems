class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpt, mpa;
        for(int el: target) mpt[el]++;
        for(int el: arr) mpa[el]++;
        return (mpt == mpa);
    }
};