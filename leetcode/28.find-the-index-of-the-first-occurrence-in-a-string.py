#
# @lc app=leetcode.cn id=28 lang=python3
# @lcpr version=30204
#
# [28] 找出字符串中第一个匹配项的下标
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
    def strStr(self, haystack: str, needle: str) -> int:
        nextp = []
        
        
# @lc code=end



#
# @lcpr case=start
# "sadbutsad"\n"sad"\n
# @lcpr case=end

# @lcpr case=start
# "leetcode"\n"leeto"\n
# @lcpr case=end

#

