#
# @lc app=leetcode.cn id=309 lang=python3
# @lcpr version=30204
#
# [309] 买卖股票的最佳时机含冷冻期
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
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0]*3 for _ in range(n)] # dp[i][0]表示第i天持有股票的最大收益，dp[i][1]表示第i天不持有股票且处于冷冻期的最大收益，dp[i][2]表示第i天不持有股票且不处于冷冻期的最大收益
        # 注意，不存在又持有股票又处于冷冻期的情况
        dp[0][0] = -prices[0] # 第0天持有股票，收益为-prices[0]
        for i in range(1,n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]) # 第i天持有股票，要么是第i-1天就持有股票，要么是第i-1天不持有股票且不处于冷冻期，第i天买入股票
            dp[i][1] = dp[i-1][0] + prices[i] # 第i天不持有股票且处于冷冻期，只能是第i-1天持有股票，第i天卖出股票
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]) # 第i天不持有股票且不处于冷冻期，要么是第i-1天不持有股票且处于冷冻期，要么是第i-1天不持有股票且不处于冷冻期
        return max(dp[n-1][1], dp[n-1][2]) # 最后一天不持有股票的最大收益            
                
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,0,2]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

