#
# @lc app=leetcode.cn id=169 lang=python3
# @lcpr version=30204
#
# [169] 多数元素
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next
# @lcpr-template-end
# @lc code=start
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, count = nums[0], 1
        for i in nums[1:]:
            count += 1 if i == ans else -1
            if count == -1:
                ans, count = i, 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [3,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,1,1,1,2,2]\n
# @lcpr case=end

#

