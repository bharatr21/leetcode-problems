class Solution {
public:
    static bool cmp(string a, string b) {
        return (a + b > b + a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string res;
        for(int el: nums) temp.push_back(to_string(el));
        sort(temp.begin(), temp.end(), cmp);
        for(string el: temp) res += el;
        return (res[0] == '0' ? "0": res);
    }
};