#
# @lc app=leetcode.cn id=47 lang=python3
# @lcpr version=30204
#
# [47] 全排列 II
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
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        vis = [False] * len(nums) # 数组记录nums中哪些数字用过
        nums.sort() # 先排序
        def dfs(tmp: list[int]):
            if len(tmp) == len(nums):
                ans.append(tmp)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i-1] == nums[i] and vis[i-1]: 
                    continue # 在这个位置，跳过所有相同的数字
                if not vis[i]: # 未用过nums[i]
                    vis[i] = True
                    dfs(tmp + [nums[i]])
                    vis[i] = False
        dfs([])
        return ans
        
# @lc code=end



#
# @lcpr case=start
# [1,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

#

if __name__ == "__main__":
    sol = Solution()
    print(sol.permuteUnique([1, 1, 2]))
    print(sol.permuteUnique([1, 2, 3]))