#
# @lc app=leetcode.cn id=3239 lang=python3
# @lcpr version=30204
#
# [3239] 最少翻转次数使二进制矩阵回文 I
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional, functools
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
class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        ansRow, ansCol = 0, 0
        for i in range(R//2):
            for j in range(C):
                if grid[i][j] != grid[R-i-1][j]:
                    ansCol += 1
        for i in range(R):
            for j in range(C//2):
                if grid[i][j] != grid[i][C-j-1]:
                    ansRow += 1
        return min(ansRow, ansCol)
        
# @lc code=end



#
# @lcpr case=start
# [[1,0,0],[0,0,0],[0,0,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,1],[0,1],[0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1],[0]]\n
# @lcpr case=end

#

