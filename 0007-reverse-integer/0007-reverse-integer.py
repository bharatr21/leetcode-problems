class Solution:
    def reverse(self, x: int) -> int:
        imax = (1 << 31) - 1
        imin = -(1 << 31)
        inp = str(x)[1:] if x < 0 else str(x)
        sgn = -1 if x < 0 else 1
        res = int(inp[::-1]) * sgn
        if res < imin or res > imax: 
            return 0
        return res
        