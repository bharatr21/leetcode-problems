class Solution:
    def reverse(self, x: int) -> int:
        imax = (1 << 31) - 1
        imin = -(1 << 31)
        sgn = -1 if x < 0 else 1
        tmp = abs(x)
        res = 0
        while tmp:
            digit = tmp % 10
            if res == imax // 10 and ((sgn == 1 and digit > 7) or (sgn == -1 and digit > 8)): return 0
            elif res > imax // 10: return 0
            res = res * 10 + digit
            tmp //= 10
        return sgn * res