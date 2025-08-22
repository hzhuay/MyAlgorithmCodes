#
# @lc app=leetcode.cn id=3195 lang=python3
# @lcpr version=30204
#
# [3195] 包含所有 1 的最小矩形面积 I
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
class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        W, H = len(grid[0]), len(grid)
        up, down, left, right = H, 0, W, 0
        for i in range(H):
            for j in range(W):
                if grid[i][j] == 1:
                    up = min(up, i)
                    down = max(down, i)
                    left = min(left, j)
                    right = max(right, j)
        return (right - left + 1) * (down - up + 1)

# @lc code=end



#
# @lcpr case=start
# [[0,1,0],[1,0,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,0],[1,0]]\n
# @lcpr case=end

#

