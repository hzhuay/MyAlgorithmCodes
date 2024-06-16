class Solution:
    def setZeroes(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])
        row = [False for i in range(n)]
        col = [False for i in range(m)]
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        for i, v in enumerate(row):
            if v:
                for j in range(m):
                    matrix[i][j] = 0
        for j, v in enumerate(col):
            if v:
                for i in range(n):
                    matrix[i][j] = 0