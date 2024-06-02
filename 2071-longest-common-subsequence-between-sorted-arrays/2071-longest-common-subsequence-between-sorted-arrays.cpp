class Solution {
public:
    vector<int> lcs(vector<int>& a1, vector<int>& a2) {
        vector<int> longest;
        int m = a1.size(), n = a2.size(), sz = min(m, n);
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(a1[i] < a2[j]) i++;
            else if(a1[i] > a2[j]) j++;
            else {longest.push_back(a2[j]); i++; j++;}
        }
        return longest;
    }

    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int n = arrays.size(), i;
        vector<int> res;
        res = lcs(arrays[0], arrays[1]);
        for(i = 2; i < n; i++)
        {
            res = lcs(res, arrays[i]);
        }
        return res;
    }
};