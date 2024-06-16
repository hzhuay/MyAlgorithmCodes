class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        # 从右上角开始搜索，过大就往左移，过小就忘下移
        n, m = len(matrix), len(matrix[0])
        r, c = 0, m-1
        while r < n and c >= 0:
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] > target:
                c -= 1
            else:
                r += 1
        return False
    
if __name__ == "__main__":
    print(Solution().searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5))