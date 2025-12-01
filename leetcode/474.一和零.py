#
# @lc app=leetcode.cn id=474 lang=python3
# @lcpr version=
#
# [474] 一和零
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
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        l = len(strs)
        dp = [[[0 for _ in range(n+1)] for _ in range(m+1)] for _ in range(l+1)] # dp[i][j][k]表示前i个元素中有j个0和k个1的最大子集
        
        ans = 0
        for i, s in enumerate(strs):
            zero = s.count("0")
            one = s.count("1")
            for j in range(0, m+1):
                for k in range(0, n+1):
                    if j >= zero and k >= one:
                        dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-zero][k-one] + 1)
                        
                    else :
                        dp[i+1][j][k] = dp[i][j][k]
                    ans = max(dp[i+1][j][k], ans)
        # print(dp)
        return ans
        
        
# @lc code=end



#
# @lcpr case=start
# ["10", "0001", "111001", "1", "0"]\n5\n3\n
# @lcpr case=end

# @lcpr case=start
# ["10", "0", "1"]\n1\n1\n
# @lcpr case=end

#

[[[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]], 
 [[0, 0, 0, 0], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1]], 
 [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 1, 1, 1], [0, 1, 2, 2], [0, 1, 2, 2]], 
 [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]], 
 [[0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1], [0, 1, 1, 1]], 
 [[0, 0, 0, 0], [1, 2, 2, 2], [1, 2, 2, 2], [1, 2, 2, 2], [1, 2, 2, 2], [1, 2, 2, 2]]]


