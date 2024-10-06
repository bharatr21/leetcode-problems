class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        minCoins = [amount + 1] * (amount + 1)
        minCoins[0] = 0
        for i in range(min(coins), amount + 1):
            for denom in coins:
                if denom <= i:
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - denom])
        
        return -1 if minCoins[amount] > amount else minCoins[amount]