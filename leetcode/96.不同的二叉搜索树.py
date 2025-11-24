#
# @lc app=leetcode.cn id=96 lang=python3
# @lcpr version=30204
#
# [96] 不同的二叉搜索树
#


# @lcpr-template-start
from re import S
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
class Solution:
    def numTrees(self, n: int) -> int:
        dp = [[0] * (n + 2) for _ in range(n + 2)] # dp[i][j]是从i到j为区间构成的二叉搜索树的数量。
        # 这个问题可以分解为，从i到j中挑选一个k作为根，构成的二叉搜索树的数量是dp[i][k-1] * dp[k+1][j]。遍历所有可能的k，累加结果，就是dp[i][j]
        
        # 所有不符合要求的区间，都初始化为1，这样相乘的时候等价于忽略
        for i in range(0, n+2):
            for j in range(0, n+2):
                if i >= j:
                    dp[i][j] = 1
        for length in range(2, n+1): # 从长度1遍历到n
            for left in range(1, n-length+2): # left从1到n-length+1
                right = left + length - 1 # 确定右边界
                for root in range(left, right+1):
                    dp[left][right] += dp[left][root-1] * dp[root+1][right]
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

if __name__ == '__main__':
    s = Solution()
    print(s.numTrees(3))