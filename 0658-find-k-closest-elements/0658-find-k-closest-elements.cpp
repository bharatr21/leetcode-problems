class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), left, right;
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for(int el: arr) {
            pq.push({abs(el - x), el});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};