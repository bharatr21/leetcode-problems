class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        n = len(matrix)
        deg = [0] * n
        for i in range(n):
            for j in range(n):
                if matrix[i][j]:
                    deg[i] += 1
                    deg[j] += 1
        deg = [d // 2 for d in deg]
        return deg
