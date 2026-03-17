#
# @lc app=leetcode.cn id=4 lang=python3
# @lcpr version=30204
#
# [4] 寻找两个正序数组的中位数
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
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 保证nums1的长度小于nums2
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m, n = len(nums1), len(nums2)
        total = m + n
        # 左半部分包含的元素个数，奇数时左半边多1个
        left_size = (total + 1) // 2
        # 在nums1上二分查找切割的位置
        low, high = 0, m
        
        while low < high:
            # 注意这里用+1实现向上取整，目的是寻找满足条件的最大i，避免死循环
            i = (low + high + 1) // 2
            j = left_size - i
            
            # nums1: [0 ... i-1] | [i ... m-1]
            # nums2: [0 ... j-1] | [j ... n-1]
            
            # 如果nums1[i-1] > nums2[j], 说明i太大，要往左缩小
            # 为什么要用i-1?
            if nums1[i-1] > nums2[j]:
                high = i - 1
            else:
                low = i
        # 此时low = high
        # 最终切割点
        i = low
        j = left_size - i
          
        # 处理边界情况，用极值代替越界
        nums1_left_max = nums1[i-1] if i > 0 else float("-inf")
        nums1_right_min = nums1[i] if i < m else float("inf")
        nums2_left_max = nums2[j-1] if j > 0 else float("-inf")
        nums2_right_min = nums2[j] if j < n else float("inf")
        
        # 左边最大值
        left_max = max(nums1_left_max, nums2_left_max)
        
        if total % 2 == 1:
            return left_max
        else:
            right_min = min(nums1_right_min, nums2_right_min)
            return (left_max + right_min) // 2


#
# @lcpr case=start
# [1,3]\n[2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n[3,4]\n
# @lcpr case=end

#

