#
# @lc app=leetcode.cn id=1143 lang=python3
# @lcpr version=30204
#
# [1143] 最长公共子序列
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
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        dp = [[0]*(m+1) for _ in range(n+1)] # dp[i][j]表示text1[0:i-1]和text2[0:j-1]的最长公共子序列长度
        for i in range(1, n+1):
            for j in range(1, m+1):
                if text1[i-1] == text2[j-1]: # 相同，长度加1
                    dp[i][j] = dp[i-1][j-1] + 1
                else: # 不同，取较大值
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][m]
        
# @lc code=end



#
# @lcpr case=start
# "abcde"\n"ace"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n"abc"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n"def"\n
# @lcpr case=end

#

