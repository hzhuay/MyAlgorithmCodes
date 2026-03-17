#
# @lc app=leetcode.cn id=15 lang=python3
# @lcpr version=30204
#
# [15] 三数之和
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
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n-2):
            if i > 0 and nums[i-1] == nums[i]: # 跳过重复数字
                continue
            target = -nums[i]
            l, r = i+1, n-1 # l和r分别是i右边区间的头尾
            while l < r :
                # 如果小就l向右，大了就r向左
                if nums[l] + nums[r] < target:
                    l += 1
                elif nums[l] + nums[r] > target:
                    r -= 1
                else: # 相等
                    ans.append([nums[i], nums[l], nums[r]])
                    
                    # 跳过重复的l和r
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    while l < r and nums[r-1] == nums[r]:
                        r -= 1
                    # 现在nums[l]!=nums[l+1]了，l再加1，下次循环从l+1开始。r同理
                    l += 1
                    r -= 1
        return ans                
            
# @lc code=end



#
# @lcpr case=start
# [-1,0,1,2,-1,-4]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,1]\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0]\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.threeSum([-100,-70,-60,110,120,130,160]))
    print(s.threeSum([1,2,0,1,0,0,0,0]))