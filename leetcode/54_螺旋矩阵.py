class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        step = [(0, 1), (1, 0), (0,-1), (-1, 0)]
        r, c = 0, -1
        n, m = len(matrix), len(matrix[0])
        target, count = n * m, 0
        i = 0
        ans = []
        MAX = 10000

        while count < target:
            next_r, next_c = r + step[i][0], c + step[i][1]
            if not (next_r >= 0 and next_r < n and next_c >=0 and next_c < m) or matrix[next_r][next_c] == MAX:
                i = (i + 1) % 4
                continue
            print(f"{next_r} {next_c}")
            ans.append(matrix[next_r][next_c])
            matrix[next_r][next_c] = MAX
            r, c = next_r, next_c
            count += 1
        return ans

if __name__ == "__main__":
    print(Solution().spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))