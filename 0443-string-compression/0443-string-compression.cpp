class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string tmp;
        char cur = chars[0];
        int le = 1;
        for(int i = 1; i < n; i++) {
            if(chars[i] == cur) le++;
            else {
                if(le > 1) tmp += cur + to_string(le);
                else tmp += cur;
                cur = chars[i];
                le = 1;
            }
        }
        if(le > 1) tmp += cur + to_string(le);
        else tmp += cur;
        copy(tmp.begin(), tmp.end(), chars.begin());
        return tmp.size();
    }
};