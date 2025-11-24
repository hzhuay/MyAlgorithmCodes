#
# @lc app=leetcode.cn id=337 lang=python3
# @lcpr version=30204
#
# [337] 打家劫舍 III
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional, Tuple
import functools, bisect

from pyparsing import col
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # 将问题转换为递归，计算我这一个节点是抢还是不抢，分别把2个结果传递给上一层来决策
        def dfs(root: Optional[TreeNode]) -> Tuple[int, int]: # 抢，不抢
            if not root:
                return 0, 0
            left_rob, left_not_rob = dfs(root.left)
            right_rob, right_not_rob = dfs(root.right)
            rob = root.val + left_not_rob + right_not_rob #本节点要抢，则左右子节点不能抢
            not_rob = max(left_rob, left_not_rob) + max(right_rob, right_not_rob) # 本节点不抢，则左右节点分别选择利益最大的抢法
            return rob, not_rob
        return max(dfs(root))
            

        
        
# @lc code=end


#
# @lcpr case=start
# [3,2,3,null,3,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,4,5,1,3,null,1]\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    