#
# @lc app=leetcode.cn id=25 lang=python3
# @lcpr version=
#
# [25] K 个一组翻转链表
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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        pre = dummy # 每次翻转的左边界的左侧
        start = head # 每次翻转的左边界

        while head:
            end = pre # 每次翻转的右边界
            for i in range(k):
                end = end.next
                if not end:
                    return dummy.next # 长度不够了直接返回
            nxt = end.next # 每次翻转的右边界的右侧

            start, end = self.reverseList(start, end)
            pre.next = start # 重新连接左边界
            end.next = nxt # 重新连接右边界
            pre = end
            start = nxt
        return dummy.next
    
    # 实现一个工具函数，将链表翻转，并返回新的头尾
    def reverseList(self, head: ListNode, tail: ListNode) -> tuple[ListNode, ListNode]:
        dummy = ListNode(0, head)
        slow = dummy
        fast = head
        while slow != tail :
            nxt = fast.next
            fast.next = slow
            slow = fast
            fast = nxt
        return tail, head
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n3\n
# @lcpr case=end

#

