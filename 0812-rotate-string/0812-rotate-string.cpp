class Solution {
public:
    string rotateLeft(string s) {
        return s.substr(1) + s[0];
    }
    bool rotateString(string s, string goal) {
        vector<string> rotations;
        int n = s.size();
        if(n == 1) return (s == goal);
        string tmp = s;
        for(int i = 1; i <= n; i++) {
            tmp = rotateLeft(tmp);
            rotations.push_back(tmp);
        }
        return (find(rotations.begin(), rotations.end(), goal) != rotations.end());
    }
};