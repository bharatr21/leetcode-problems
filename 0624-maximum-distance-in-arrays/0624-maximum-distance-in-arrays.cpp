class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        vector<int> mxs, mns;
        for(int i = 0; i < m; i++) {
            int n = arrays[i].size();
            mxs.push_back(arrays[i][n-1]);
            mns.push_back(arrays[i][0]);
        }
        int mx = -10001, mxidx = -10001, smx = -10001, mn = 10001, smn = 10001, mnidx = -1;
        for(int i = 0; i < m; i++) {
            if(mx < mxs[i]) {
                smx = mx;
                mx = mxs[i];
                mxidx = i;
            } else if(smx < mxs[i]) {
                smx = mxs[i];
            }
        }
        for(int i = 0; i < m; i++) {
            if(mn > mns[i]) {
                smn = mn;
                mn = mns[i];
                mnidx = i;
            } else if(smn > mns[i]) {
                smn = mns[i];
            }
        }
        if(mxidx == mnidx) return max(smx - mn, mx - smn);
        else return (mx - mn);
    }
};