#
# @lc app=leetcode.cn id=1035 lang=python3
# @lcpr version=30204
#
# [1035] 不相交的线
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
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        # 这个题目和最长公共子序列是一样的
        n, m = len(nums1), len(nums2)
        dp = [[0]*(m+1) for _ in range(n+1)] # dp[i][j]表示nums1[0:i-1]和nums2[0:j-1]的不相交线的最大数量
        for i in range(1, n+1):
            for j in range(1, m+1):
                if nums1[i-1] == nums2[j-1]: # 相同，数量加1
                    dp[i][j] = dp[i-1][j-1] + 1
                else: # 不同，取较大值
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][m]
        
# @lc code=end



#
# @lcpr case=start
# [1,4,2]\n[1,2,4]\n
# @lcpr case=end

# @lcpr case=start
# [2,5,1,2,5]\n[10,5,2,1,5,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,3,7,1,7,5]\n[1,9,2,5,1]\n
# @lcpr case=end

#

