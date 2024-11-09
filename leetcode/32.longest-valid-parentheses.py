#
# @lc app=leetcode.cn id=32 lang=python3
# @lcpr version=30204
#
# [32] 最长有效括号
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
    def longestValidParentheses(self, s: str) -> int:
        
# @lc code=end



#
# @lcpr case=start
# "(()"\n
# @lcpr case=end

# @lcpr case=start
# ")()())"\n
# @lcpr case=end

# @lcpr case=start
# ""\n
# @lcpr case=end

#

