#
# @lc app=leetcode.cn id=646 lang=python3
# @lcpr version=30204
#
# [646] 最长数对链
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools
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
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        pairs.sort(key=lambda x: x[1]) # 按照右端点排序
        cur = pairs[0]
        ans = 1
        for i in range(1, n):
            if pairs[i][0] > cur[1]:
                cur = pairs[i]
                ans += 1
        return ans
# @lc code=end



#
# @lcpr case=start
# [[1,2], [2,3], [3,4]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2],[7,8],[4,5]]\n
# @lcpr case=end

#

