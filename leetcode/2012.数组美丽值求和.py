#
# @lc app=leetcode.cn id=2012 lang=python3
# @lcpr version=30204
#
# [2012] 数组美丽值求和
#


# @lcpr-template-start
import enum
from turtle import left
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
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        leftMax = [0 for i in range(n)] # 往左看的最大值
        rightMin = [0 for i in range(n)] # 往右看的最小值
        
        for i, v in enumerate(nums):
            j = n - 1 - i
            if i == 0 or i == n - 1:
                leftMax[i] = v
                rightMin[j] = nums[j]
            else:
                leftMax[i] = max(leftMax[i-1], v)
                rightMin[j] = min(rightMin[j+1], nums[j])

        ans = 0
        for i, v in enumerate(nums):
            if i == 0 or i == n - 1:
                continue
            if leftMax[i-1] < v and v < rightMin[i+1]:
                ans += 2
            elif nums[i-1] < v and v < nums[i+1]:
                ans += 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,4,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [3,2,1]\n
# @lcpr case=end

#

