#
# @lc app=leetcode.cn id=392 lang=python3
# @lcpr version=30204
#
# [392] 判断子序列
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
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        if len(s) == 0:
            return True
        i, j = 0, 0
        while j < len(t):
            if t[j] == s[i]:
                i += 1
            j += 1
            if i == len(s):
                return True
        return False
# @lc code=end



#
# @lcpr case=start
# "abc"\n"ahbgdc"\n
# @lcpr case=end

# @lcpr case=start
# "axc"\n"ahbgdc"\n
# @lcpr case=end

# @lcpr case=start
# "b"\n"c"\n
# @lcpr case=end

# 

