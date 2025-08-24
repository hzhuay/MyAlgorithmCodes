#
# @lc app=leetcode.cn id=5 lang=python3
# @lcpr version=30204
#
# [5] 最长回文子串
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
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        dp = [[False]*n for _ in range(n)] # dp[i][j]表示s[i..j]是否是回文串
        for i in range(n):
            dp[i][i] = True # 单个字符是回文串
        max_len = 1
        ans = s[0]
        for i in range(1, n):
            for j in range(i):
                if s[i] == s[j]:
                    if i - j < 3: # 要么是aba，要么是aa
                        dp[j][i] = True
                    else:
                        dp[j][i] = dp[j+1][i-1] # 如果s[j+1..i-1]是回文串，那么s[j..i]也是回文串
                if max_len < i - j + 1 and dp[j][i]: # 记录目前遇到的最长回文串
                    max_len = i - j + 1
                    ans = s[j:i+1]
        return ans
                        
        
        
# @lc code=end



#
# @lcpr case=start
# "babad"\n
# @lcpr case=end

# @lcpr case=start
# "cbbd"\n
# @lcpr case=end

#

