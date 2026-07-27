class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mx, smx = 0, 0
        for el in nums:
            if mx <= el:
                smx, mx = mx, el
            elif smx <= el:
                smx = el
        return (mx - 1) * (smx - 1)