#
# @lc app=leetcode.cn id=2466 lang=python3
# @lcpr version=
#
# [2466] 统计构造好字符串的方案数
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
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        
# @lc code=end



#
# @lcpr case=start
# 3\n3\n1\n1\n
# @lcpr case=end

# @lcpr case=start
# 2\n3\n1\n2\n
# @lcpr case=end

#

