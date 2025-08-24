#
# @lc app=leetcode.cn id=740 lang=python3
# @lcpr version=30204
#
# [740] 删除并获得点数
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
    def deleteAndEarn(self, nums: List[int]) -> int:
        score = [0] * 10001
        for num in nums:
            score[num] += num
        dp = [0] * 10001
        dp[1] = score[1]
        for i in range(2, 10001):
            dp[i] = max(dp[i-1], dp[i-2] + score[i])
        return dp[10000]

# @lc code=end



#
# @lcpr case=start
# [3,4,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,3,3,3,4]\n
# @lcpr case=end

#

