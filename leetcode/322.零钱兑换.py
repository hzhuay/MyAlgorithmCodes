#
# @lc app=leetcode.cn id=322 lang=python3
# @lcpr version=30204
#
# [322] 零钱兑换
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
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0] + [-1] * amount # dp[i]表示到达i金额的最小硬币数量
        for c in coins:
            for i in range(c, amount+1):
                if dp[i-c] == 0:
                    dp[i] = 1
                elif dp[i-c] > 0:
                    if dp[i] == -1:
                        dp[i] = dp[i - c] + 1
                    else:
                        dp[i] = min(dp[i], dp[i - c] + 1)
                i += c
        # print(dp)
        return dp[amount]
                    
        
# @lc code=end



#
# @lcpr case=start
# [1, 2, 5]\n11\n
# @lcpr case=end

# @lcpr case=start
# [2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#

if __name__ == '__main__':
    s = Solution()
    s.coinChange([1, 2, 5], 11)