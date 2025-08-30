#
# @lc app=leetcode.cn id=516 lang=python3
# @lcpr version=30204
#
# [516] 最长回文子序列
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
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0]*n for _ in range(n)] # dp[i][j]表示s[i..j]的最长回文子序列长度
        for i in range(n):
            dp[i][i] = 1 # 单个字符是回文串，长度为1
        max_len = 1
        for r in range(1, n):
            for l in range(r - 1, -1, -1): # 注意遍历顺序，从短到长，右边界往后，左边界往前
                if s[l] == s[r]:
                    dp[l][r] = dp[l+1][r-1] + 2 # 状态转移思路：如果s[l] == s[r]，那么最长回文子序列长度等于s[l+1..r-1]的最长回文子序列长度加2
                    max_len = max(max_len, dp[l][r])
                else:
                    dp[l][r] = max(dp[l+1][r], dp[l][r-1])
        # print(dp)
        return max_len
        
# @lc code=end



#
# @lcpr case=start
# "bbbab"\n
# @lcpr case=end

# @lcpr case=start
# "cbbd"\n
# @lcpr case=end

#
if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindromeSubseq("abacccba"))
    print(s.longestPalindromeSubseq("cbbd"))
