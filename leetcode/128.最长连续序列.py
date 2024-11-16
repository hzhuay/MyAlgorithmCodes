#
# @lc app=leetcode.cn id=128 lang=python3
# @lcpr version=
#
# [128] 最长连续序列
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
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for v in nums:
            if (v - 1) in s:
                continue # 跳过，让连续数中最小的来处理
            offset = 1
            while (v + offset) in s:
                offset += 1
            ans = max(ans, offset)
        return ans

# @lc code=end



#
# @lcpr case=start
# [100,4,200,1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [0,3,7,2,5,8,4,6,0,1]\n
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().longestConsecutive([100,4,200,1,3,2]))
    print(Solution().longestConsecutive([0,3,7,2,5,8,4,6,0,1]))