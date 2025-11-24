#
# @lc app=leetcode.cn id=123 lang=python3
# @lcpr version=30204
#
# [123] 买卖股票的最佳时机 III
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
        dp = [[0] * 4 for _ in range(n)]
        # dp[i][j]表示第i天，进行了j次操作后的最大收益。j=0是第一次买入，j=1是第一次卖出，j=2是第二次买入，j=3是第二次卖出
        # 注意，j=0时必须买入，如dp[0][0]表示第一天买入。由于理论上可以当天买卖，所以输出结果时可以只输出2次交易后的收益，即dp[-1][-1]
        dp[0]= [-prices[0], 0, -prices[0], 0]
        for i in range(1, n):
            # first buy
            dp[i][0] = max(dp[i-1][0], -prices[i]) # 继续持有，或者买入。注意这里结束后必须手里有股票
            # first sell
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]) # 持有，或者卖出
            # 如果2次交易优于1一次，那么接下来这两步就会体现出来。如果没有更好，那么就会保持不变
            # second buy
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i])
            # second sell
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i])
        return dp[-1][-1]
# @lc code=end



#
# @lcpr case=start
# [3,3,5,0,0,3,1,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,4,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.maxProfit([1,2,3,4,5]))
    print(s.maxProfit([7,6,4,3,1]))