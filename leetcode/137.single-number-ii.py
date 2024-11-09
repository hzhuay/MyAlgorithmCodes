#
# @lc app=leetcode.cn id=137 lang=python3
# @lcpr version=30204
#
# [137] 只出现一次的数字 II
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
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
    def singleNumber(self, nums: List[int]) -> int:
        first = 0
        for i in nums:
            first ^= i
        # first代表每个数字都亦或了一次，因为出现3次的有2次抵消了
        second = sum(nums) ^ first
        return sum(nums) ^ first
# @lc code=end



#
# @lcpr case=start
# [2,2,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,0,1,0,1,99]\n
# @lcpr case=end

#

