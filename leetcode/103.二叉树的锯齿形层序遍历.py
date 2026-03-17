#
# @lc app=leetcode.cn id=103 lang=python3
# @lcpr version=30204
#
# [103] 二叉树的锯齿形层序遍历
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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = [root]
        ans = []
        while len(q) > 0:
            tmp = []
            ans.append([])
            for node in q:
                ans[-1].append(node.val)
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            q = tmp

        for i in range(len(ans)):
            if i % 2 == 1:
                ans[i].reverse()
        return ans
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#

