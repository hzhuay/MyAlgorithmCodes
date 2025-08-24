#
# @lc app=leetcode.cn id=746 lang=python3
# @lcpr version=30204
#
# [746] 使用最小花费爬楼梯
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
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n+1)
        for i in range(2, n+1):
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
        return dp[n]
        
# @lc code=end



#
# @lcpr case=start
# [10,15,20]\n
# @lcpr case=end

# @lcpr case=start
# [1,100,1,1,1,100,1,1,100,1]\n
# @lcpr case=end

#

