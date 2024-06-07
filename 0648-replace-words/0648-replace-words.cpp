class Solution {
public:
    static bool cmp(string s1, string s2) {
            return ((s1.size() == s2.size()) ? (s1 < s2) : (s1.size() < s2.size()));
    }
    string replace(vector<string>& dictionary, string target) {
        for(string check: dictionary) {
            if(target.rfind(check, 0) == 0) return check;
        }
        return target;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> res; 
        string ans;
        vector<string> words;
        istringstream iss(sentence);
        string word;
        sort(dictionary.begin(), dictionary.end(), cmp);
        while(getline(iss, word, ' ')) {
            words.push_back(word);
        }
        for(string word: words) {
            res.push_back(replace(dictionary, word));
        }
        for(string el: res) ans += el + " ";
        return ans.substr(0, ans.size() - 1);
    }
};