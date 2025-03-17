class Solution {
public:
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd, int bStart, int bEnd) {
        if(aEnd < aStart) return B[k - aStart];
        if(bEnd < bStart) return A[k - bStart];
        int aIndex = (aStart + aEnd) / 2;
        int bIndex = (bStart + bEnd) / 2;
        int aVal = A[aIndex], bVal = B[bIndex];
        if(aIndex + bIndex < k) {
            //Discard smaller left half
            if(aVal > bVal) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        } else {
            //Discard larger right half
            if(aVal > bVal) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int na = nums1.size(), nb = nums2.size();
        if((na + nb) % 2) {
            return solve(nums1, nums2, (na + nb)/2, 0, na - 1, 0, nb - 1);
        } else {
            return (1.0 * solve(nums1, nums2, (na + nb)/2 - 1, 0, na - 1, 0, nb - 1) +
            solve(nums1, nums2, (na + nb)/2, 0, na - 1, 0, nb - 1)) / 2;
        }
    }
};