#
# @lc app=leetcode.cn id=540 lang=python3
# @lcpr version=
#
# [540] 有序数组中的单一元素
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
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums) # 一定是奇数，目标下标一定是偶数
        l, r, mid = 0, n, 0 # 左闭右闭
        while l < r:
            mid = (l + r - 1) // 2 
            if nums[mid] == nums[mid ^ 1]: # mid是奇数时，和左边比。是偶数时和右边比
                l = mid + 1
            else:
                r = mid
        return nums[l]

# @lc code=end



#
# @lcpr case=start
# [1,1,2,3,3,4,4,8,8]\n
# @lcpr case=end

# @lcpr case=start
# [3,3,7,7,10,11,11]\n
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().singleNonDuplicate([1,1,2,3,3,4,4,8,8]))
    print(Solution().singleNonDuplicate([3,3,7,7,10,11,11]))
    print(Solution().singleNonDuplicate([1,1,2]))



