#
# @lc app=leetcode.cn id=146 lang=python3
# @lcpr version=30204
#
# [146] LRU 缓存
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools, bisect

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lcpr-template-end
# @lc code=start
class ListNode:
    def __init__(self, key=0, val=0, next=None, prev=None):
       self.val = val
       self.key = key
       self.next = next
       self.prev = prev
    
    def __repr__(self) -> str:
        return f"(key={self.val}, prev={self.prev.val if self.prev else 'None'}, next={self.next.val if self.next else 'None'}"

class LRUCache:

    def __init__(self, capacity: int):
        import heapq
        self.m = dict[int, ListNode]() # 查询数据
        self.heap = [] # 维护使用次数
        self.cap = capacity
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def __remove_node(self, node: ListNode):
        node.prev.next = node.next
        node.next.prev = node.prev
        
    def __push_head(self, node: ListNode):
        node.next = self.head.next
        node.prev = self.head
        node.next.prev = node
        self.head.next = node
    
    def __push_tail(self, node: ListNode):
        node.next = self.tail
        node.prev = self.tail.prev
        self.tail.prev = node
        node.prev.next = node

    def __move_to_head(self, node: ListNode):
        self.__remove_node(node)
        self.__push_head(node)


    def get(self, key: int) -> int:
        if key not in self.m or self.m[key] == None:
            return -1
        node = self.m[key]

        # 节点挪到链表头部
        self.__move_to_head(node)
        return node.val        

    def put(self, key: int, value: int) -> None:
        if key in self.m and self.m[key]:
            node = self.m[key]
            node.val = value
            self.__move_to_head(node)
        else:
            node = ListNode(key, value)
            self.__push_head(node)
            self.m[key] = node
            
            if len(self.m) > self.cap:
                remove = self.tail.prev
                self.__remove_node(remove)
                del self.m[remove.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @lc code=end



