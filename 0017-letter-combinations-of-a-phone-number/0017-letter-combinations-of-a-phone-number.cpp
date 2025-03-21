class Solution {
public:
    void backtrack(string digits, int idx, vector<string>& res, string tmp, unordered_map<char, vector<char>>& digitMap) {
        if(idx == digits.size()) {
            if(!tmp.empty()) res.push_back(tmp);
            return;
        }
        else {
            while(!digitMap.count(digits[idx])) idx++;
            if(idx == digits.size()) return;
            for(char c: digitMap[digits[idx]]) {
                tmp += c;
                backtrack(digits, idx + 1, res, tmp, digitMap);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char, vector<char>> digitMap;
        digitMap['2'] = {'a', 'b', 'c'};
        digitMap['3'] = {'d', 'e', 'f'};
        digitMap['4'] = {'g', 'h', 'i'};
        digitMap['5'] = {'j', 'k', 'l'};
        digitMap['6'] = {'m', 'n', 'o'};
        digitMap['7'] = {'p', 'q', 'r', 's'};
        digitMap['8'] = {'t', 'u', 'v'};
        digitMap['9'] = {'w', 'x', 'y', 'z'};
        string tmp;
        backtrack(digits, 0, res, tmp, digitMap);
        return res;
    }
};