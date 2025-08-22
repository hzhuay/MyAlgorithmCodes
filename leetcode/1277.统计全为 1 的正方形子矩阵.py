#
# @lc app=leetcode.cn id=1277 lang=python3
# @lcpr version=30204
#
# [1277] 统计全为 1 的正方形子矩阵
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
    def countSquares(self, matrix: List[List[int]]) -> int:
        
        
# @lc code=end



#
# @lcpr case=start
# [[0,1,1,1],[1,1,1,1],[0,1,1,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,0,1],[1,1,0],[1,1,0]]\n
# @lcpr case=end

#

