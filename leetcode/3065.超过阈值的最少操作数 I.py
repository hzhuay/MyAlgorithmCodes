#
# @lc app=leetcode.cn id=3065 lang=python3
# @lcpr version=30204
#
# [3065] 超过阈值的最少操作数 I
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
    def minOperations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == k:
                right = mid - 1
            elif nums[mid] < k:
                left = mid + 1
            else:
                right = mid - 1
        if nums[left] != k:
            return left
        return left
        
# @lc code=end



#
# @lcpr case=start
# [2,11,10,1,3]\n10\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,1,2,4,9]\n9\n
# @lcpr case=end

#

if __name__ == "__main__":
    print(Solution().minOperations([2,11,10,1,3],10))
    print(Solution().minOperations([760340387,289254123,628299234,204198715,565672759,684967229,303459334,302262994,770720781,383343826,148523784,750183433,778902176,930418501,520286131,441750197,402643198,547480026,799770607,303114486,481644752,320289220,792197603,44751343,828179295,804048578,468569446,555743704,416141129,865011209,56010709,133835994,200083188,740956911,842527451,728469270,370323078,880010797,977376598,598070033,866374140,110775975,609860085],377260496))