#
# @lc app=leetcode.cn id=354 lang=python3
# @lcpr version=30204
#
# [354] 俄罗斯套娃信封问题
#


# @lcpr-template-start
from curses.ascii import SO
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
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        # envelopsy已经按宽度排序了，问题转换为了求高度的最长递增子序列，由于问题规模不能用n^2的dp解决，所以用nlogn的二分法
        height = [envelopes[i][1] for i in range(n)]
        lis = [height[0]]
        for i in range(1, n):
            if height[i] > lis[-1]: # 如果比lis尾部还大，直接加入
                lis.append(height[i])
            else: # 比lis尾部小或等于，则lis可以优化
                # 用二分法找到第一个大于等于height[i]的位置，替换掉
                idx = bisect.bisect_left(lis, height[i])
                lis[idx] = height[i]
        return len(lis)
            
        
# @lc code=end



#
# @lcpr case=start
# [[5,4],[6,4],[6,7],[2,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1],[1,1],[1,1]]\n
# @lcpr case=end

#
if __name__ == "__main__":
    s = Solution()
    print(s.maxEnvelopes([[1,3],[3,5],[6,7],[6,8],[8,4],[9,5]]))
    print(s.maxEnvelopes([[46, 89], [50, 53], [52, 68], [72, 45], [77, 81]]))
    print(s.maxEnvelopes([[6,10],[11,14],[6,1],[16,14],[13,2]]
))
    

