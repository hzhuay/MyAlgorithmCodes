#
# @lc app=leetcode.cn id=56 lang=python3
# @lcpr version=30204
#
# [56] 合并区间
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
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0]) # 按照左边界排序
        ans = []
        tmp = []
        for i, v in enumerate(intervals):
            l, r = v
            if tmp == []: 
                tmp = v
            elif tmp[0] <= l and l <= tmp[1]:
                tmp[1] = max(r, tmp[1])
            elif tmp[1] < l:
                ans.append(tmp)
                tmp = v
        if tmp != []:
            ans.append(tmp)
        return ans
            
        
# @lc code=end



#
# @lcpr case=start
# [[1,3],[2,6],[8,10],[15,18]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,4],[4,5]]\n
# @lcpr case=end

#

