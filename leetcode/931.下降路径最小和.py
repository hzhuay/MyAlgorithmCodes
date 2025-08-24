#
# @lc app=leetcode.cn id=931 lang=python3
# @lcpr version=30204
#
# [931] 下降路径最小和
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
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[0] * n for _ in range(n)]
        dp[0] = matrix[0].copy()
        for i in range(1, n):
            for j in range(n):
                if j == 0: # 左边界
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j]
                elif j == n-1: # 右边界
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + matrix[i][j]
        return min(dp[-1])
        
# @lc code=end



#
# @lcpr case=start
# [[2,1,3],[6,5,4],[7,8,9]]\n
# @lcpr case=end

# @lcpr case=start
# [[-19,57],[-40,-5]]\n
# @lcpr case=end

#

