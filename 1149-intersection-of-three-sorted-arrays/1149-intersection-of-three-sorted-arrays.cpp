class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int p1 = 0, p2 = 0, p3 = 0;
        while(p1 < n1 && p2 < n2 && p3 < n3) {
            if(arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
                res.push_back(arr1[p1]);
                p1++; p2++; p3++;
            }
            else if(arr1[p1] <= arr2[p2] && arr1[p1] <= arr3[p3]) p1++;
            else if(arr2[p2] <= arr1[p1] && arr2[p2] <= arr3[p3]) p2++;
            else if(arr3[p3] <= arr1[p1] && arr3[p3] <= arr2[p2]) p3++;
        }
        return res;
    }
};