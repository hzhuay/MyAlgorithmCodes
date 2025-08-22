#
# @lc app=leetcode.cn id=22 lang=python3
# @lcpr version=30204
#
# [22] 括号生成
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
    def generateParenthesis(self, n: int) -> List[str]:
        ans = set()
        def dfs(dif, cur, s):
            if cur == n and dif == 0: # 加满了
                ans.add(s)
                return
            if dif > 0 : # 允许再加右括号
                dfs(dif - 1, cur, s + ')')
            if cur < n: # 还可以加左括号
                dfs(dif + 1, cur + 1, s + '(')
        dfs(0, 0, '')
        return list(ans)
        
# @lc code=end



#
# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

