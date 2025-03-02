class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cur_dir = 0;
        int x = 0, y = 0;
        for(char instr: instructions) {
            switch(instr) {
                case 'G': {x = x + dirs[cur_dir].first; y = y + dirs[cur_dir].second; break;}
                case 'L': {cur_dir = (cur_dir + 3) % 4; break;}
                case 'R': {cur_dir = (cur_dir + 1) % 4; break;}
            }
        }
        return (cur_dir != 0 || (x == 0 && y == 0));
    }
};