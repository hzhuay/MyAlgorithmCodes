#
# @lc app=leetcode.cn id=160 lang=python3
# @lcpr version=30204
#
# [160] 相交链表
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools, bisect
from uuid import NIL
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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:  
        if not headA or not headB:
            return None
        a, b = headA, headB
        while a != b:
            a = (a.next if a else headB)
            b = (b.next if b else headA)
        return a
# @lc code=end



#
# @lcpr case=start
# 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
# @lcpr case=end

# @lcpr case=start
# 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
# @lcpr case=end

# @lcpr case=start
# 0\n[2,6,4]\n[1,5]\n3\n2\n
# @lcpr case=end

#

