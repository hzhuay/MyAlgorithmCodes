#
# @lc app=leetcode.cn id=62 lang=python3
# @lcpr version=30204
#
# [62] 不同路径
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
    def uniquePaths(self, m: int, n: int) -> int:
        # 初始化一个二维数组
        dp = [[0] * n for _ in range(m)]
        # 设置起点
        dp[0][0] = 1
        # 填充数组
        for i in range(m):
            for j in range(n):
                if i > 0: # 可以从上面来
                    dp[i][j] += dp[i - 1][j]
                if j > 0: # 可以从左边来
                    dp[i][j] += dp[i][j - 1]
        return dp[m - 1][n - 1]

# @lc code=end



#
# @lcpr case=start
# 3\n7\n
# @lcpr case=end

# @lcpr case=start
# 3\n2\n
# @lcpr case=end

# @lcpr case=start
# 7\n3\n
# @lcpr case=end

# @lcpr case=start
# 3\n3\n
# @lcpr case=end

#

