#
# @lc app=leetcode.cn id=46 lang=python3
# @lcpr version=
#
# [46] 全排列
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional, functools
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
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        vis = [False] * len(nums) # 数组记录nums中哪些数字用过
        def dfs(tmp: list[int]):
            if len(tmp) == len(nums):
                ans.append(tmp)
                return
            for i in range(len(nums)):
                if not vis[i]: # 未用过nums[i]
                    vis[i] = True
                    dfs(tmp + [nums[i]])
                    vis[i] = False
        dfs([])
        print(ans)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [0,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

if __name__=="__main__":
    Solution().permute([1,2,3])