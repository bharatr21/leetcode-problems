class Compare {
    public:
    bool operator()(vector<int>& p1, vector<int>& p2) {
        return p1[0] < p2[0];
    }
};

class Solution {
public:
    int dist(vector<int>& point) {
        return (point[0] * point[0] + point[1] * point[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(vector<int> point: points) {
            pq.push({dist(point), point[0], point[1]});
            if(pq.size() > k) {
                auto u = pq.top();
                pq.pop();
            }            
        }
        while(!pq.empty())
        {
            auto u = pq.top();
            res.push_back({u[1], u[2]});
            pq.pop();
        }
        return res;
    }
};