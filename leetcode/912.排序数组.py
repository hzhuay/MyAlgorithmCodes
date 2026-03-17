#
# @lc app=leetcode.cn id=912 lang=python3
# @lcpr version=30204
#
# [912] 排序数组
#


# @lcpr-template-start
from operator import le
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
    def sortArray(self, nums: List[int]) -> List[int]:
        
        def swap(i, j):
            nums[i], nums[j] = nums[j], nums[i]
        def quick_sort(left, right):
            if left >= right:
                return
            import random
            pivot_idx = random.randint(left, right)
            pivot_val = nums[pivot_idx]
            
            lt = left  # nums[left ... lt-1] < pivot_val
            gt = right # nums[gt+1 ... right] > pivot_val
            i = left # nums[lt ... i-1] == pivot_val
            
            while i <= gt:
                if nums[i] < pivot_val:
                    swap(i, lt)
                    lt += 1
                    i += 1
                elif nums[i] > pivot_val:
                    swap(i, gt)
                    gt -= 1
                    # 注意i不能动，因为gt变过了，等于这时候是固定nums[i],从右向左逐个检查nums[gt]
                else:
                    i += 1
            quick_sort(left, lt - 1)
            quick_sort(gt + 1, right)
        quick_sort(0, len(nums)-1)
        return nums
    

        
# @lc code=end



#
# @lcpr case=start
# [5,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [5,1,1,2,0,0]\n
# @lcpr case=end

#

