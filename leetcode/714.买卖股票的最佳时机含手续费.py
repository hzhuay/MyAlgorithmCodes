#
# @lc app=leetcode.cn id=714 lang=python3
# @lcpr version=30204
#
# [714] 买卖股票的最佳时机含手续费
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
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        dp = [[0]*2 for _ in range(n)] # dp[i][0]表示第i天持有股票的最大收益，dp[i][1]表示第i天不持有股票的最大收益
        dp[0][0] = -prices[0] # 第0天持有股票，收益为-prices[0]
        for i in range(1,n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]) # 要么继续持有，要么从前一天买入
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee) # 要么继续不持有，要么从前一天卖出
        return dp[n-1][1]
        
# @lc code=end



#
# @lcpr case=start
# [1, 3, 2, 8, 4, 9]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,3,7,5,10,3]\n3\n
# @lcpr case=end

#

