class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> spar;
        if(n == 0) return {""};
        else
        {
            int left;
            for(left = 0; left < n; left++)
            {
                vector<string> leftset = generateParenthesis(left);
                vector<string> rightset = generateParenthesis(n - 1 - left);
                for(string lefts: leftset)
                {
                    for(string rights: rightset)
                    {
                        spar.insert("(" + lefts + ")" + rights);
                    }
                }
            }
        }
        vector<string> res(spar.begin(), spar.end());
        return res;
    }
};