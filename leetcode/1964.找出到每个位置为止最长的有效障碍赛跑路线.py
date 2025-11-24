#
# @lc app=leetcode.cn id=1964 lang=python3
# @lcpr version=30204
#
# [1964] 找出到每个位置为止最长的有效障碍赛跑路线
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
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        n = len(obstacles)
        # 这道题的本质是求每一个位置的最长非下降子序列。
        # 但是由于问题规模是10^5，所以不能用O(n^2)的方式
        ans = [1]
        lis = [obstacles[0]]
        for i in range(1, n):
            if obstacles[i] >= lis[-1]: # 如果比lis尾部还大，直接加入
                lis.append(obstacles[i])
                ans.append(len(lis))
            else: # 比lis尾部小或等于，则lis可以优化
                # 题目要求obstacles[i]必须要选用，所以要找到obstacles[i]可以插入哪里，比obstacles[i]大的要舍弃
                idx = bisect.bisect_right(lis, obstacles[i])
                lis[idx] = obstacles[i]
                ans.append(idx+1)
            # print(lis)
        return ans

# @lc code=end



#
# @lcpr case=start
# [1,2,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,5,6,4,2]\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.longestObstacleCourseAtEachPosition([1,2,3,2]))
    print(s.longestObstacleCourseAtEachPosition([2,2,1]))
    print(s.longestObstacleCourseAtEachPosition([3,1,5,6,4,2]))
    print(s.longestObstacleCourseAtEachPosition([7,7,7]))