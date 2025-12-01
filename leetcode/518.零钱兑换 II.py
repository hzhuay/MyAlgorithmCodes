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
        # dp = [1] + [0] * amount # dp[i]表示达到i金额最多有多少种可能
        # # dp[i][j]表示用前i种硬币能达到j金额有多少方案
        # for i in coins:
        #     for j in range(1, amount+1):
        #         if j >= i:
        #             dp[j] += dp[j - i]
        # return dp[amount]
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(n):
             for j in range(amount+1):
                if coins[i] > j:
                    dp[i+1][j] = dp[i][j]
                else:
                    dp[i+1][j] = dp[i][j] + dp[i+1][j-coins[i]]
        # print(dp)
        return dp[n][amount]
         
        
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

if __name__ == '__main__':
    s = Solution()
    print(s.change(4, [1,2,3]))