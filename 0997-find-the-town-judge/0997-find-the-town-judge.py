class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        notJudge = set()
        cand = 1
        for a, b in trust:
            notJudge.add(a)
            if b not in notJudge:
                cand = b
        if cand in notJudge: return -1
        return cand if all([[i, cand] in trust for i in range(1, n+1) if i != cand]) else -1

