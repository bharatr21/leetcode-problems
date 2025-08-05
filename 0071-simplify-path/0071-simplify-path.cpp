class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string tmp;
        vector<string> stk;
        while(getline(ss, tmp, '/')) {
            if(tmp == "..") {
                if(!stk.empty()) stk.pop_back();
            } else if(tmp != "." && !tmp.empty()) {
                stk.push_back(tmp);
            }
        }
        string res = "";
        for(auto s: stk) res += "/" + s;
        return ((res.empty()) ? "/" : res);
    }
};