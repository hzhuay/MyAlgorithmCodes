#
# @lc app=leetcode.cn id=72 lang=python3
# @lcpr version=30204
#
# [72] 编辑距离
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
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0]*(m+1) for _ in range(n+1)] # dp[i][j]表示word1[0:i-1]和word2[0:j-1]的编辑距离
        # 初始化，很关键
        for i in range(1, n+1):
            dp[i][0] = i # word2是空串，编辑距离等于word1的长度
        for j in range(1, m+1):
            dp[0][j] = j # word1是空串，编辑距离等于word2的长度
        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]: # 相同，不需要操作
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                
        return dp[n][m]
        
        
        
        
# @lc code=end



#
# @lcpr case=start
# "horse"\n"ros"\n
# @lcpr case=end

# @lcpr case=start
# "intention"\n"execution"\n
# @lcpr case=end

#

