class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        inter = sorted(intervals, key = lambda x: (x[0], -x[1]))
        a, n = inter[0], len(inter)
        res = n
        max_end = a[1]
        for i in range(1, n):
            b = inter[i]
            if b[1] <= max_end:
                res -= 1
            else:
                max_end = b[1]

        return res