#
# @lc app=leetcode.cn id=518 lang=python3
# @lcpr version=30204
#
# [518] 零钱兑换 II
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
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [1] + [0] * amount # dp[i]表示达到i金额最多有多少种可能
        for i in range(1, amount+1):
            for j in coins:
                if i >= j and dp[i-j] > 0:
                    dp[i] += dp[i-j]
        print(dp)
        return dp[amount]
         
        
# @lc code=end



#
# @lcpr case=start
# 5\n[1, 2, 5]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[2]\n
# @lcpr case=end

# @lcpr case=start
# 10\n[10]\n
# @lcpr case=end

#

