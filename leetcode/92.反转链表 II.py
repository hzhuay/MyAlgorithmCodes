#
# @lc app=leetcode.cn id=92 lang=python3
# @lcpr version=30204
#
# [92] 反转链表 II
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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        """
        反转链表从位置 left 到 right 的部分（1-indexed）
        思路：
          1. 找到 left-1 节点（记为 pre_start）和 left 节点（记为 start）
          2. 对 [left, right] 进行标准反转（迭代）
          3. 重新连接三段：[1..left-1] + [reversed part] + [right+1..end]
        """
        if not head or left == right:
            return head
        
        dummy = ListNode(0, head) # 创建一个虚拟节点，统一处理left=1的情况
        pre_start = dummy
        
        # 找到 left-1 节点（pre_start）和 left 节点（start）
        for _ in range(left-1):
            pre_start = pre_start.next
        start = pre_start.next # 反转区间的起点
        
        # 反转从start开始的 right - left + 1个节点
        # 用三指针反转，注意prev初始化为None
        prev = None
        curr = start
        for _ in range(right - left + 1):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        # 此时，prev是反转后的新头，curr是right+1节点并且可能为None，start是反转后的尾节点
        pre_start.next = prev
        start.next = curr
        
        return dummy.next
        
     
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5]\n2\n4\n
# @lcpr case=end

# @lcpr case=start
# [5]\n1\n1\n
# @lcpr case=end

#

