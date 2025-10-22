class SparseVector {
public:
    vector<pair<int, int>> sp;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i]) sp.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int m = sp.size(), n = vec.sp.size(), i = 0, j = 0;
        int res = 0;
        while(i < m && j < n) {
            if(sp[i].first == vec.sp[j].first) {
                res += sp[i].second * vec.sp[j].second;
                i++;
                j++;
            }
            else if(sp[i].first < vec.sp[j].first) i++;
            else j++;
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);