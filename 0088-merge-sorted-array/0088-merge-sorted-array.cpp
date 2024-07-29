class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> nums1c(nums1.begin(), nums1.end());
        for(k = 0; k < m + n; k++)
        {
            if(j >= n || (i < m && nums1c[i] <= nums2[j])) {
                nums1[k] = nums1c[i++];
            }
            else {
                nums1[k] = nums2[j++];
            }
        }
    }
};