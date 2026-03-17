#
# @lc app=leetcode.cn id=215 lang=python3
# @lcpr version=30204
#
# [215] 数组中的第K个最大元素
#


# @lcpr-template-start
from re import L
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
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        target = n - k # 第k大，就是第n-k小

        def swap(i, j):
            nums[i], nums[j] = nums[j], nums[i]

       
        def quick_search(left, right):
            if left == right:
                return left
            import random
            pivot_idx = random.randint(left, right)
            pivot_val = nums[pivot_idx]

            lt = left # nums[left ... lt-1] < pivot_val
            i = left # nums[lt ... i] = pivot_val
            gt = right # nums[gt+1 ... right] < pivot_val

            while i <= gt:
                if nums[i] < pivot_val:
                    swap(lt, i)
                    lt += 1
                    i += 1        
                elif nums[i] > pivot_val:
                    swap(gt, i)
                    gt -= 1
                else:
                    i += 1
            # 现在：
            # [left, lt) < pivot
            # [lt, gt] == pivot   ← 注意：是闭区间！
            # (gt, right] > pivot

            if gt < target:
                return quick_search(gt + 1, right)
            elif target < lt:
                return quick_search(left, lt - 1)
            else:
                return lt
            
        return nums[quick_search(0, n-1)]
            
        

    def findKthLargestByHeap(self, nums: List[int], k: int) -> int:
        # 构建一个大小为k的小顶堆，如果超过就弹出最小的那个，遍历完成后，堆头就是数组中前K大的元素里最小的
        # 但是复杂度超过了
        import heapq
        h = []
        for i in nums:
            heapq.heappush(h, i)
            if len(h) > k:
                heapq.heappop(h)
        return h[0]
# @lc code=end



#
# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 4\n
# @lcpr case=end

#

