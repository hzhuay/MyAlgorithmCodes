#
# @lc app=leetcode.cn id=326 lang=python3
# @lcpr version=30204
#
# [326] 3 的幂
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
    def isPowerOfThree(self, n: int) -> bool:
        # 3本身是个质数，3^19是int范围内最大的3的幂，如果n是3的幂，那么3^19 % n == 0
        return n > 0 and 3**19 % n == 0
        
# @lc code=end



#
# @lcpr case=start
# 27\n
# @lcpr case=end

# @lcpr case=start
# 0\n
# @lcpr case=end

# @lcpr case=start
# 9\n
# @lcpr case=end

# @lcpr case=start
# 45\n
# @lcpr case=end

#

