class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res = []
        for word in words:
            if(all(w.lower() in "qwertyuiop" for w in word) or all(w.lower() in "asdfghjkl" for w in word) or all(w.lower() in "zxcvbnm" for w in word)):
                res.append(word)
        return res
