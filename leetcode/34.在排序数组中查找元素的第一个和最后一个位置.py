#
# @lc app=leetcode.cn id=34 lang=python3
# @lcpr version=30204
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
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
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return [self.binary_search(nums, target, True), self.binary_search(nums, target, False)]
    def binary_search(self, nums: List[int], target: int, is_lower: bool) -> int:
        l = 0
        r = len(nums) - 1
        ret = -1
        while l <= r:
            mid = (l + r) // 2
            if target < nums[mid]:
                r = mid - 1
            elif target > nums[mid]:
                l = mid + 1
            else:
                ret = mid
                if is_lower:
                    r = mid - 1
                else:
                    l = mid + 1
        return ret
# @lc code=end



#
# @lcpr case=start
# [5,7,7,8,8,10]\n8\n
# @lcpr case=end

# @lcpr case=start
# [5,7,7,8,8,10]\n6\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end

#

