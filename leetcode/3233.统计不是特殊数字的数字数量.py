#
# @lc app=leetcode.cn id=3233 lang=python3
# @lcpr version=30204
#
# [3233] 统计不是特殊数字的数字数量
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
    def nonSpecialCount(self, l: int, r: int) -> int:
        def getPrime(n):
            prime = []
            vis = [False] * (n + 1)
            for i in range(2, n + 1):
                if not vis[i] : # 是质数
                    prime.append(i)
                    tmp = i + i
                    while tmp <= n:
                        vis[tmp] = True
                        tmp += i
            return prime
        prime = getPrime(10**5)
        ans = r - l + 1
        for i in prime:
            if i ** 2 >= l and i ** 2 <= r:
                ans -= 1
            elif i ** 2 > r:
                break
        return ans
        
        
        
# @lc code=end



#
# @lcpr case=start
# 5\n7\n
# @lcpr case=end

# @lcpr case=start
# 4\n16\n
# @lcpr case=end

# @lcpr case=start
# 1\n5\n
# @lcpr case=end

# @lcpr case=start
# 1\n8\n
# @lcpr case=end

#

