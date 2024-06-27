# @lcpr-before-debug-begin
from python3problem105 import *
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=105 lang=python3
# @lcpr version=30204
#
# [105] 从前序与中序遍历序列构造二叉树
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if preorder == [] or inorder == []:
            return None
        rootVal = preorder[0]
        rootIdx = inorder.index(rootVal) # 中序遍历中，根节点的坐标

        leftIn = inorder[0:rootIdx] # 左子树的中序遍历
        rightIn = inorder[rootIdx+1:] # 右子树的中序遍历

        leftPre = preorder[1:1+len(leftIn)] # 左子树的前序遍历
        rightPre = preorder[1+len(leftIn):] # 右子树的前序遍历

        root = TreeNode(rootVal, self.buildTree(leftPre, leftIn), self.buildTree(rightPre, rightIn))
        return root
# @lc code=end



#
# @lcpr case=start
# [3,9,20,15,7]\n[9,3,15,20,7]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

