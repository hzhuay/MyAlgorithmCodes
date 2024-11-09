#
# @lc app=leetcode.cn id=10 lang=python3
# @lcpr version=
#
# [10] 正则表达式匹配
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
    def isMatch(self, s: str, p: str) -> bool:
        
# @lc code=end



#
# @lcpr case=start
# "aa"\n"a"\n
# @lcpr case=end

# @lcpr case=start
# "aa"\n"a*"\n
# @lcpr case=end

# @lcpr case=start
# "ab"\n".*"\n
# @lcpr case=end

#

