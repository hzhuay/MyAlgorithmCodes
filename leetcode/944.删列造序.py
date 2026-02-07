#
# @lc app=leetcode.cn id=944 lang=python3
# @lcpr version=30204
#
# [944] 删列造序
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
    def minDeletionSize(self, strs: List[str]) -> int:
        
# @lc code=end



#
# @lcpr case=start
# ["cba","daf","ghi"]\n
# @lcpr case=end

# @lcpr case=start
# ["a","b"]\n
# @lcpr case=end

# @lcpr case=start
# ["zyx","wvu","tsr"]\n
# @lcpr case=end

#

