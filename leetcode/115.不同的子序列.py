#
# @lc app=leetcode.cn id=115 lang=python3
# @lcpr version=30204
#
# [115] 不同的子序列
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
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        # dp[i][j]表示s[:i]的子序列中t[:j]的数量
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        # 初始化，如果t[:j]是空串，则s[:i]的子序列一定包含
        for i in range(n):
            dp[i][0] = 1
        for i in range(0, n):
            for j in range(0, m):
                if s[i] == t[j]:
                   # 字符相同，从前面的状态累加。由于定义是包含t[:j]，所以t[:j]不能缩小，要看s[:i-1]和s[:i]包含t[:j]的情况.
                   # 要么s和t都缩减一个字符，要么只有s缩减一个
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1]
                else:
                    # 不同，状态只能来自s少一个字符
                    dp[i+1][j+1] = dp[i][j+1]
        return dp[n][m]


# @lc code=end



#
# @lcpr case=start
# "rabbbit"\n"rabbit"\n
# @lcpr case=end

# @lcpr case=start
# "babgbag"\n"bag"\n
# @lcpr case=end

#
if __name__ == "__main__":
    s = "rabbbit"
    t = "rabbit"
    solution = Solution()
    print(solution.numDistinct(s, t))
