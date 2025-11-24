#
# @lc app=leetcode.cn id=1262 lang=python3
# @lcpr version=
#
# [1262] 可被三整除的最大和
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
    def maxSumDivThree(self, nums: List[int]) -> int:
        # 用三个数组，记录 mod0, mod1, mod2的元素
        nums.sort()
        mod = [[], [], []]
        for i in nums:
            mod[i % 3].append(i)
        
        one = mod[1]
        two = mod[2]
        len1 = len(one)
        len2 = len(two)
        total = sum(nums)
        
        if total % 3 == 0:
            return total
        if total % 3 == 1: # 要么舍弃1个最小的mod1，要么最小的2个mod2
            if len1 >= 1 and len2 >= 2:
                return total - min(one[0], two[0] + two[1])
            elif len1 >= 1:
                return total - one[0]
        if total % 3 == 2:
            if len2 >= 1 and len1 >= 2:
                return total - min(two[0], one[0] + one[1])
            elif len2 >= 1:
                return total - two[0]
        return sum(mod[0])
                
            
            
        
            
        

# @lc code=end



#
# @lcpr case=start
# [3,6,5,1,8]\n
# @lcpr case=end

# @lcpr case=start
# [4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,4]\n
# @lcpr case=end

#

s = Solution()
print(s.maxSumDivThree([1,1,3]))