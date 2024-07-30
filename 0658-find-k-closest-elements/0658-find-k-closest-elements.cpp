struct Comparator {
    int additional;
    Comparator(int arg): additional(arg) {}
    bool operator()(int a, int b) const {
        return ((abs(a - additional) == abs(b - additional)) ? (a < b) : (abs(a - additional) < abs(b - additional)));
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        sort(arr.begin(), arr.end(), Comparator(x));
        for(int i = 0; i < k; i++) res.push_back(arr[i]);
        sort(res.begin(), res.end());
        return res;
    }
};