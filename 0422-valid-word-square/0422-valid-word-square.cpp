class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        for(int i = 0; i < m; i++) {
            for(size_t j = 0; j < words[i].size(); j++) {
                if(j >= m || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};