#
# @lc app=leetcode.cn id=75 lang=python3
# @lcpr version=30204
#
# [75] 颜色分类
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
    
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def swap(i, j):
            nums[i], nums[j] = nums[j], nums[i]
        
        n = len(nums)
        pivot_val = 1
        lt = 0
        gt = n - 1
        i = 0
        
        while i <= gt:
            if nums[i] < pivot_val:
                swap(i, lt)
                i += 1
                lt += 1
            elif nums[i] > pivot_val:
                swap(i, gt)
                gt -= 1
            else:
                i += 1
        
          
    
    def sortColors_quicksort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        def swap(i, j):
            nums[i], nums[j] = nums[j], nums[i]
        
        def quick_sort(left, right):
            if left >= right:
                return

            import random
            pivot_val = nums[random.randint(left, right)]
            lt = left   # nums[left ... lt-1] < pivot_val
            i = left    # nums[lt ... gt] == pivot_val
            gt = right  # nums[gt+1 ... right] < pivot_val
            
            while i <= gt:
                if nums[i] < pivot_val:
                    swap(i, lt)
                    lt += 1
                    i += 1
                elif nums[i] > pivot_val:
                    swap(i, gt)
                    gt -= 1
                else:
                    i += 1
            
            quick_sort(left, lt-1)
            quick_sort(gt+1, right)
        
        quick_sort(0, len(nums)-1)
        
            
            
# @lc code=end



#
# @lcpr case=start
# [2,0,2,1,1,0]\n
# @lcpr case=end

# @lcpr case=start
# [2,0,1]\n
# @lcpr case=end

#

