#
# @lc app=leetcode.cn id=1218 lang=python3
# @lcpr version=30204
#
# [1218] 最长定差子序列
#


# @lcpr-template-start
from re import S
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
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n = len(arr)
        dp = {} # dp[i]表示以arr[i]结尾的最长定差子序列
        ans = 1
        for i in range(0, n):
            pre = arr[i] - difference
            if pre in dp:
                dp[arr[i]] = dp[pre] + 1
                ans = max(dp[arr[i]], ans)
            else:
                dp[arr[i]] = 1
        return ans

# @lc code=end



#
# @lcpr case=start
# [1,2,3,4]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,3,5,7]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,5,7,8,5,3,4,2,1]\n-2\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.longestSubsequence([1,1,1,2,2,2], 1))
