#
# @lc app=leetcode.cn id=179 lang=python3
# @lcpr version=30204
#
# [179] 最大数
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional, functools
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

class Tmp:
    def __init__(self, n):
        self.s = str(n)
    
    def __lt__(self, other):
        return self.s + other.s > other.s + self.s


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        numStrs = list(map(lambda x: Tmp(x), nums))
        numStrs = sorted(numStrs)
        strs = list(map(lambda x: x.s, numStrs))
        ans = functools.reduce(lambda x,y: x+y, strs)
        i = 0
        while i < len(ans) and ans[i] == '0':
            i += 1
        if i == len(ans):
            return '0'
        return ans[i:]
    
# @lc code=end



#
# @lcpr case=start
# [10,2]\n
# @lcpr case=end

# @lcpr case=start
# [3,30,34,5,9]\n
# @lcpr case=end

# @lcpr case=start
# [0,0]\n
# @lcpr case=end

# @lcpr case=start
# [0,1]\n
# @lcpr case=end
#

