#
# @lc app=leetcode.cn id=55 lang=python3
# @lcpr version=30204
#
# [55] 跳跃游戏
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
    def canJump(self, nums: List[int]) -> bool:
        N = len(nums)
        far = 0 # 维护当前能到的最远距离
        for i in range(N):
            if i > far:
                return False
            far = max(far, i + nums[i])
            if far >= N - 1:
                return True
        return False

# @lc code=end



#
# @lcpr case=start
# [2,3,1,1,4]\n
# @lcpr case=end

# @lcpr case=start
# [3,2,1,0,4]\n
# @lcpr case=end

#
if __name__ == "__main__":
    solution = Solution()
    print(solution.canJump([2,3,1,1,4]))
    print(solution.canJump([3,2,1,0,4]))
    print(solution.canJump([0]))
    print(solution.canJump([2,0,0]))