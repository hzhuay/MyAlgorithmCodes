#
# @lc app=leetcode.cn id=1027 lang=python3
# @lcpr version=30204
#
# [1027] 最长等差数列
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
import functools, collections
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
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[1] * 1001 for _ in range(n)] # 初始化
        # dp[i][j]是以nums[i]结尾的公差为j的最长等差子序列长度
        ans = 1
        for i in range(1, n):
            for j in range(i):
                dif = nums[i] - nums[j] # dif可能为负
                dp[i][dif] = dp[j][dif] + 1 # Python的数组下标支持负数，正好适配，不需要手动加偏移
                ans = max(ans, dp[i][dif])
        # print(dp)
        return ans
                    
            
        
# @lc code=end



#
# @lcpr case=start
# [3,6,9,12]\n
# @lcpr case=end

# @lcpr case=start
# [9,4,7,2,10]\n
# @lcpr case=end

# @lcpr case=start
# [20,1,15,3,10,5,8]\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.longestArithSeqLength([3,6,9,12]))

