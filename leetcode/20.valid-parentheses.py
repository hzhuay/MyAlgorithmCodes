#
# @lc app=leetcode.cn id=20 lang=python3
# @lcpr version=30204
#
# [20] 有效的括号
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next
# @lcpr-template-end
# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match_left = {"(": ")", "[": "]", "{": "}"}
        match_right = {")": "(", "]": "[", "}": "{"}
        for i in s:
            if i in match_left:
                stack.append(i)
            else:
                if len(stack) == 0 or stack.pop() != match_right[i]:
                    return False
        return len(stack) == 0
# @lc code=end



#
# @lcpr case=start
# "()"\n
# @lcpr case=end

# @lcpr case=start
# "()[]{}"\n
# @lcpr case=end

# @lcpr case=start
# "(]"\n
# @lcpr case=end

# @lcpr case=start
# "("\n
# @lcpr case=end

# @lcpr case=start
# ")"\n
# @lcpr case=end

#

