class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return ((p1.second == p2.second) ? p1.first < p2.first : p1.second > p2.second);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> boxes;
        for(vector<int>& v: boxTypes) {
            boxes.push_back({v[0], v[1]});            
        }
        sort(boxes.begin(), boxes.end(), cmp);
        int cur = 0, res = 0, i = 0;
        while(i < n && cur < truckSize) {
            if(cur + boxes[i].first <= truckSize) {
                cur += boxes[i].first;
                res += boxes[i].first * boxes[i].second;
            } else {
                res += (truckSize - cur) * boxes[i].second;
                cur = truckSize;
            }
            i++;
        }
        return res;
    }
};