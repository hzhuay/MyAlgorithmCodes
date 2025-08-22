#
# @lc app=leetcode.cn id=122 lang=python3
# @lcpr version=30204
#
# [122] 买卖股票的最佳时机 II
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
        # 这道题就是要找出所有的上升子序列。由于是支持T+0，所以可以只看今天和昨天的价格差，有得赚就买卖，没有赚就不动
        prices.append(0)  # 手动给最后一天设置为0，认为到期后还不清仓就不算了
        ans = 0
        for i in range(1, len(prices)):
            ans += max(0, prices[i] - prices[i-1])
        return ans
        
# @lc code=end



#
# @lcpr case=start
# [7,1,5,3,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,4,3,1]\n
# @lcpr case=end

#

