#
# @lc app=leetcode.cn id=300 lang=python3
# @lcpr version=30204
#
# [300] 最长递增子序列
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
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1]*n # dp[i]表示以nums[i]结尾的最长递增子序列的长度
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
        
    # 用二分，可以优化到O(NlogN)
    def lengthOfLISBuuyBinarySearch(self, nums: List[int]) -> int:
        n = len(nums)
        lis = [] # lis[i]的定义是长度为i+1的lis，结尾元素即最大值是lis[i]
        # 贪心：为了让后续能接更多数字，我们希望相同长度的递增子序列末尾尽可能小。
        # 最终lis数组长度，就是答案
        for i in range(n):
            idx = bisect.bisect_left(lis, nums[i])
            if idx == len(lis): # 如果比lis尾部还大，直接加入
                lis.append(nums[i])
            else: # 比lis尾部小或等于，则lis可以优化
                # 用二分法找到第一个大于等于nums[i]的位置，替换掉
                lis[idx] = nums[i]
        return len(lis)

# @lc code=end



#
# @lcpr case=start
# [10,9,2,5,3,7,101,18]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,0,3,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [7,7,7,7,7,7,7]\n
# @lcpr case=end

#
if __name__ == "__main__":
    s = Solution()
    s.lengthOfLISByBinarySearch([8,4,6,3,7,2])

