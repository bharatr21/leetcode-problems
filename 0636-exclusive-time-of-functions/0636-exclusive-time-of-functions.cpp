class Solution {
public:
    vector<string> split(string s, char delim) {
        vector<string> comps;
        size_t pos_end;
        while((pos_end = s.find(delim)) != string::npos) {
            comps.push_back(s.substr(0, pos_end));
            s.erase(0, pos_end + 1);
        }
        comps.push_back(s);
        return comps;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> stk;
        int m = logs.size();
        string s = logs[0];
        char delim = ':';
        vector<string> comps = split(s, delim);
        int id = stoi(comps[0]), time = stoi(comps[2]);
        stk.push(id);
        for(int i = 1; i < m; i++) {
            string s = logs[i];         
            char delim = ':';
            vector<string> comps = split(s, delim);
            int id = stoi(comps[0]);
            string state = comps[1];
            if(state == "start") {
                if(!stk.empty()) res[stk.top()] += stoi(comps[2]) - time;
                stk.push(id);
                time = stoi(comps[2]);
            } else {
                res[stk.top()] += stoi(comps[2]) - time + 1;
                stk.pop();
                time = stoi(comps[2]) + 1;
            }
        }
        return res;
    }
};