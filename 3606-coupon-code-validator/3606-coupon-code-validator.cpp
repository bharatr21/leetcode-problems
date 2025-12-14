class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> inter;
        vector<string> res;
        int n = code.size();
        for(int i = 0; i < n; i++) {
            if(isActive[i]) {
                if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") {
                    bool flag = true;
                    if(code[i] == "") {flag = false;}
                    for(char c: code[i]) {
                        if(!isalnum(c) && c != '_') {
                            flag = false;
                            break;
                        }
                    }
                if(flag) inter.push_back({businessLine[i], code[i]});  
            }
        }
        }
        sort(inter.begin(), inter.end());
        for(auto el: inter) {
            res.push_back(el.second);
        }
        return res;
    }
};