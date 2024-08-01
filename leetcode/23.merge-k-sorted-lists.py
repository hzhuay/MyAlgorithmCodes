#
# @lc app=leetcode.cn id=23 lang=python3
# @lcpr version=
#
# [23] 合并 K 个升序链表
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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # 重载运算符
        ListNode.__lt__ = lambda a, b : a.val < b.val
        dummy = cur = ListNode()
        heap = [head for head in lists if head] # 所有的头加入列表
        import heapq
        heapq.heapify(heap)
        while heap :
            tmp = heapq.heappop(heap)
            if tmp.next:
                heapq.heappush(heap, tmp.next)
            cur.next = tmp
            cur = cur.next
        return dummy.next
# @lc code=end



#
# @lcpr case=start
# [[1,4,5],[1,3,4],[2,6]]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

# @lcpr case=start
# [[]]\n
# @lcpr case=end

#

