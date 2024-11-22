#
# @lc app=leetcode.cn id=200 lang=python3
# @lcpr version=30204
#
# [200] 岛屿数量
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lcpr-template-end
# @lc code=start


class Dsu:
    def __init__(self, size: int):
        self.pa = list(range(size))

    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    # 合并函数，将x合并到y
    def union(self, x, y):
        self.pa[self.find(x)] = self.find(y)


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        R, C = len(grid), len(grid[0])
        vis = [[0 for i in range(C)] for j in range(R)]  # 用于标记哪些访问过

        def dfs(r, c, mark):
            if r < 0 or c < 0 or r >= R or c >= C or vis[r][c] != 0 or grid[r][c] != '1':
                return
            vis[r][c] = mark
            dfs(r+1, c, mark)
            dfs(r-1, c, mark)
            dfs(r, c+1, mark)
            dfs(r, c-1, mark)
        mark = 1
        for i in range(R):
            for j in range(C):
                if vis[i][j] == 0 and grid[i][j] == '1':
                    dfs(i, j, mark)
                    mark += 1
        return mark - 1
# @lc code=end


#
# @lcpr case=start
# [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
# @lcpr case=end

# @lcpr case=start
# [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
# @lcpr case=end

#
