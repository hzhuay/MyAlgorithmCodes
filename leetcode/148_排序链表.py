from leetcode import *

class Solution:
    def merge(self, head1: ListNode, head2: ListNode) -> ListNode:
        dummy = ListNode(0)
        tmp, l, r = dummy, head1, head2
        while l and r:
            if l.val <= r.val:
                tmp.next = l
                l = l.next
            else:
                tmp.next = r
                r = r.next
            tmp = tmp.next
        if l: # 拼接剩余链表
            tmp.next = l
        elif r:
            tmp.next = r
        return dummy.next

    def getLength(self, head: Optional[ListNode]) -> int:
        node = head
        length = 0
        while node:
            length += 1
            node = node.next
        return length
    
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        length = self.getLength(head)
        subLen = 1
        while subLen < length:
            # 确定每一轮的子区间
            pre, cur = dummy, dummy.next
            while cur:
                head1 = cur # 该子区间内的前半
                for i in range(1, subLen):
                    if cur.next:
                        cur = cur.next
                    else:
                        break

                head2 = cur.next # 该子区间的后半
                cur.next = None # 截断
                cur = head2
                for i in range(1, subLen):
                    if cur and cur.next:
                        cur = cur.next
                    else:
                        break
                
                end = None
                if cur:
                    end = cur.next
                    cur.next = None # 截断
                cur = end # cur下一轮的起点，是这一次归并的2个子区间的后面
                merged = self.merge(head1, head2)
                pre.next = merged
                while pre.next: # 下一轮的pre，应该是下一轮要合并的子区间的头部的前一个，也就是本轮的最后一个
                    pre = pre.next
            subLen <<= 1
        return dummy.next
