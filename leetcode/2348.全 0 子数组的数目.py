#
# @lc app=leetcode.cn id=2348 lang=python3
# @lcpr version=30204
#
# [2348] 全 0 子数组的数目
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
        self.pre = [0] * 100005
        for i in range(1, 100005):
            self.pre[i] = self.pre[i - 1] + i
                    
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        last = -1
        ans = 0
        has_zero = False
        nums.append(1) # 手动加一个非0的数作为终止
        for i in range(len(nums)):
            if nums[i] != 0 :
                if has_zero:
                    zeros = i - last - 1 # 目前为止有几个0
                    ans += self.pre[zeros]
                    # print(f'nums[i]={nums[i]} i={i} last={last}, zeros={zeros} add={self.pre[zeros]}')
                last = i
                has_zero = False
            else:
                has_zero = True    
        return ans

# @lc code=end



#
# @lcpr case=start
# [1,3,0,0,2,0,0,4]\n
# @lcpr case=end

# @lcpr case=start
# [0,0,0,2,0,0]\n
# @lcpr case=end

# @lcpr case=start
# [2,10,2019]\n
# @lcpr case=end

#

# 本地调试
if __name__ == '__main__':
    sol = Solution()
    print(sol.zeroFilledSubarray([1,3,0,0,2,0,0,4]))
    print(sol.zeroFilledSubarray([0,0,0,2,0,0]))
    print(sol.zeroFilledSubarray([2,10,2019]))
    print(sol.zeroFilledSubarray([0]*100000))