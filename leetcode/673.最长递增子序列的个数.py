#
# @lc app=leetcode.cn id=673 lang=python3
# @lcpr version=30204
#
# [673] 最长递增子序列的个数
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
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n # dp[i]是nums[:i]内的最长递增子序列的长度 
        cnt = [1] * n # cnt[i]表示nums[:i]内的最长递增子序列的数量
        max_len = 0
        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]: # 最长递增子序列的长度变长了
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j] # 继承前面的计数
                    elif dp[j] + 1 == dp[i]: # 最长递增子序不变
                        cnt[i] += cnt[j] # 叠加前面的计数
        max_len = max(dp)
        return sum(cnt[i] for i in range(n) if dp[i] == max_len)


# @lc code=end



#
# @lcpr case=start
# [1,3,5,4,7]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,2,2]\n
# @lcpr case=end

#

