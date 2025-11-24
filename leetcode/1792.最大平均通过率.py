#
# @lc app=leetcode.cn id=1792 lang=python3
# @lcpr version=30204
#
# [1792] 最大平均通过率
#


# @lcpr-template-start
from queue import PriorityQueue
from typing import List, ClassVar, Dict, Optional
import heapq
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
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        heap = []
        n = len(classes)
        def push(a, b):
            # 应该按照加入一个优等生后的涨幅来排序
            heapq.heappush(heap, (a/b-(a+1)/(b+1), a, b))
        def pop():
            return heapq.heappop(heap)

        for a, b in classes:
            push(a, b)
        # print(heap)

        while extraStudents > 0:
            diff, a, b = pop()
            push(a + 1, b + 1)
            # print(heap)
            extraStudents -= 1

        total = sum(a / b for _, a, b in heap)
        return total / n
# @lc code=end


#
# @lcpr case=start
# [[1,2],[3,5],[2,2]]\n2\n
# @lcpr case=end

# @lcpr case=start
# [[2,4],[3,9],[4,5],[2,10]]\n4\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.maxAverageRatio([[1,2],[3,5],[2,2]], 2))
    print(s.maxAverageRatio([[2,4],[3,9],[4,5],[2,10]], 4))