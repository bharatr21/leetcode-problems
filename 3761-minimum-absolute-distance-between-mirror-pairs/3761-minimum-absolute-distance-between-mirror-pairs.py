def mirror(n: int) -> int:
    res = 0
    while n:
        res = res * 10 + (n % 10)
        n //= 10
    return res

class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        imap = {}
        n = len(nums)
        res = n + 1
        for idx, el in enumerate(nums):
            if el in imap:
                res = min(res, idx - imap[el])
            imap[mirror(el)] = idx
        return -1 if res > n else res

