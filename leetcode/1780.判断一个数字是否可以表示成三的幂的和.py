#
# @lc app=leetcode.cn id=1780 lang=python3
# @lcpr version=30204
#
# [1780] 判断一个数字是否可以表示成三的幂的和
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
    def __init__(self) -> None:
        i = 1
        self.total = set([0])
        while i <= 10**7:
            tmp = list(self.total)
            for v in tmp:
                self.total.add(v + i)
            i *= 3
        self.total = self.total - {0}
    
    def checkPowersOfThree(self, n: int) -> bool:
        return n in self.total
        
        
        
        
# @lc code=end



#
# @lcpr case=start
# 12\n
# @lcpr case=end

# @lcpr case=start
# 91\n
# @lcpr case=end

# @lcpr case=start
# 21\n
# @lcpr case=end

#

if __name__ == "__main__":
    sol = Solution()
    print(sol.checkPowersOfThree(12))
    print(sol.checkPowersOfThree(21))
