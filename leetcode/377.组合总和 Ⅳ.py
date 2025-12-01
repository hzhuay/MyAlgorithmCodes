#
# @lc app=leetcode.cn id=377 lang=python3
# @lcpr version=30204
#
# [377] 组合总和 Ⅳ
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
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [1] + [0] * target # dp[i]表示达到i金额最多有多少种可能
        for i in range(1, target+1):
            for j in nums:
                if i >= j:
                    dp[i] += dp[i-j]
        # print(dp)
        return dp[target]
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n4\n
# @lcpr case=end

# @lcpr case=start
# [9]\n3\n
# @lcpr case=end

#

if __name__ == '__main__':
    s = Solution()
    print(s.combinationSum4([1,2,3], 4))