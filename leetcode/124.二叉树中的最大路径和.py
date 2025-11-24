#
# @lc app=leetcode.cn id=124 lang=python3
# @lcpr version=30204
#
# [124] 二叉树中的最大路径和
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # 对于每个节点，是否要算上自己，取决于自己加上左右子树的最大值，是否优于只选一边
        ans = 0
        def dfs(root: Optional[TreeNode]):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            ans = max(left, right, )
            return max(0, root.val + left + right)
            
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [-10,9,20,null,null,15,7]\n
# @lcpr case=end

#

