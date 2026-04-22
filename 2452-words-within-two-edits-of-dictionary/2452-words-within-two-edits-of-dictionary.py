def twoEdits(word1: str, word2: str, n: int) -> bool:
    return sum([word1[i] != word2[i] for i in range(n)]) <= 2

class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        n = len(queries[0])
        res = []
        for q in queries:
            for word in dictionary:
                if twoEdits(q, word, n):
                    res.append(q)
                    break
        return res
