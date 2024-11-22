#
# @lc app=leetcode.cn id=825 lang=python3
# @lcpr version=
#
# [825] 适龄的朋友
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
    def numFriendRequests(self, ages: List[int]) -> int:
        ages.sort() # 排序，因为每人只会给年龄更小的人发
        n = len(ages)
        ans = 0
        l, r = 0, 0
        for age in ages:
            if age <= 14:
                continue
            while ages[l] <= 0.5 * age + 7:
                l += 1
            while r < n and ages[r] <= age: # 目标：ages[r]是比age大的最新小数
                r += 1
            ans += r - l - 1
        return ans     
        
        
        
# @lc code=end



#
# @lcpr case=start
# [16,16]\n
# @lcpr case=end

# @lcpr case=start
# [16,17,18]\n
# @lcpr case=end

# @lcpr case=start
# [20,30,100,110,120]\n
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().numFriendRequests([16,16]))
    print(Solution().numFriendRequests([16,17,18]))
    print(Solution().numFriendRequests([20,30,100,110,120]))