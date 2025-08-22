#
# @lc app=leetcode.cn id=3238 lang=python3
# @lcpr version=30204
#
# [3238] 求出胜利玩家的数目
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
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        count = {}
        for x, y in pick:
            if x not in count:
                count[x] = 1
            else:
                count[x] += 1
        ans = 0
        for k, v in count.items():
            if v >= k + 1:
                ans += 1
        return ans
        
        
# @lc code=end



#
# @lcpr case=start
# 4\n[[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]\n
# @lcpr case=end

# @lcpr case=start
# 5\n[[1,1],[1,2],[1,3],[1,4]]\n
# @lcpr case=end

# @lcpr case=start
# 5\n[[1,1],[2,4],[2,4],[2,4]]\n
# @lcpr case=end

#

