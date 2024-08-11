class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counts(n+1, 0);
        for(int el: citations) {
            counts[min(el, n)]++;
        }
        int k = n;
        for(int i = counts[n]; k > i; i += counts[k]) k--;
        return k;
    }
};