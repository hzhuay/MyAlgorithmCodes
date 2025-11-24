#
# @lc app=leetcode.cn id=188 lang=python3
# @lcpr version=30204
#
# [188] 买卖股票的最佳时机 IV
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
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0] * (2*k) for _ in range(n)]
        # dp[i][j]表示第i天，进行了j次操作后的最大收益。j=0是第一次买入，j=1是第一次卖出。以此类推，j=2*(k-1)是第k次买入，j=2*k-1是第k次卖出
        # 注意，j=0时必须买入，如dp[0][0]表示第一天买入。由于理论上可以当天买卖，所以输出结果时可以只输出2次交易后的收益，即dp[-1][-1]
        dp[0]= [-prices[0] if i%2==0 else 0 for i in range(2*k)]
        for i in range(1, n):
            for j in range(2*k):
                if j % 2 == 0: # 买入
                    if j == 0: # 第一次买入，之前成本为0
                        dp[i][j] = max(dp[i-1][j], -prices[i])
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]) 
                else: # 卖出
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]) # 持有，或者卖出
        return dp[-1][-1]
# @lc code=end



#
# @lcpr case=start
# 2\n[2,4,1]\n
# @lcpr case=end

# @lcpr case=start
# 2\n[3,2,6,5,0,3]\n
# @lcpr case=end

#

