#
# @lc app=leetcode.cn id=95 lang=python3
# @lcpr version=30204
#
# [95] 不同的二叉搜索树 II
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools, bisect
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        dp = [[[None] for _ in range(n+2)] for _ in range(n + 2)] # dp[i][j]是从i到j为区间构成的所有二叉搜索树的树根
        # 这个问题可以分解为，dp[i][j]是从i到j中挑选一个k作为根，所有可能的左子树是dp[i][k-1]，右子树是dp[k+1][j]
        # 把dp[i][k-1]和dp[k+1][j]所有可能的组合加起来，就是在i到j的范围内以k为树根的所有二叉搜索树
        for length in range(1, n+1): # 从长度1遍历到n
            for i in range(1, n-length+2): # left从1到n-length+1
                j = i + length - 1 # 确定右边界
                dp[i][j] = []
                for k in range(i, j+1):
                    for left in dp[i][k-1]:
                        for right in dp[k+1][j]:
                            dp[i][j].append(TreeNode(k, left, right))
        return dp[1][n]
# @lc code=end



#
# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

