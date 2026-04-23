class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        hmap = defaultdict(list)
        n = len(nums)
        res = [0] * n
        for i, v in enumerate(nums):
            hmap[v].append(i)
        for el in hmap.values():
            total = sum(el)
            m = len(el)
            pref = 0
            if m == 1:
                res[el[0]] = 0
                break
            for i, idx in enumerate(el):
                res[idx] = total - 2 * pref + idx * (2 * i - m)
                pref += idx
        return res