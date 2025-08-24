#
# @lc app=leetcode.cn id=63 lang=python3
# @lcpr version=30204
#
# [63] 不同路径 II
#


# @lcpr-template-start
from re import S
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
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        # 初始化一个二维数组
        dp = [[0] * m for _ in range(n)]
        # 设置起点
        dp[0][0] = 1
        # 填充数组
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1: # 遇到障碍物
                    dp[i][j] = 0
                    continue
                if i > 0: # 可以从上面来
                    dp[i][j] += dp[i - 1][j]
                if j > 0: # 可以从左边来
                    dp[i][j] += dp[i][j - 1]
        return dp[-1][-1]

# @lc code=end



#
# @lcpr case=start
# [[0,0,0],[0,1,0],[0,0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,1],[0,0]]\n
# @lcpr case=end

#

if __name__ == '__main__':
    s = Solution()
    print(s.uniquePathsWithObstacles([[0,0]]))