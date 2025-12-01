#
# @lc app=leetcode.cn id=2140 lang=python3
# @lcpr version=
#
# [2140] 解决智力问题
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
    def mostPoints(self, questions: List[List[int]]) -> int:
        # l = len(questions)
        # dp = [[0, 0] for _ in range(l+1)] # dp[i][j]表示截止第i个问题，选择跳过或者解决可以得到的最高分。0跳过，1解决
        # questions.insert(0, [0, 0])
        # # dp[1][1] = questions[0][0]
        # for i in range(1, l+1):
        #     p, _ = questions[i]
        #     # 跳过则默认继承前一题目的最大分数
        #     dp[i][0] = max(dp[i-1])
        #     for j in range(i):
        #         _, b = questions[j]
        #         if j + b < i: # 可以解题
        #             dp[i][1] = max(dp[i][1], dp[j][1] + p)
        # # print(dp)
        # return max(dp[l])
        
        # 上面这个版本会超时，用记忆化搜索好理解一点
        
        @functools.cache
        def dfs(i: int) -> int: # 定义dfs(i)是从第i个问题开始解决的最高分
            if i >= len(questions):
                return 0
            p, b = questions[i]
            return max(dfs(i+1) , p + dfs(i + b + 1)) # 要么选择跳过，则从i+1继承。如果选择解题，则下一个状态是跳过b之后的题目
        return dfs(0)
        
                
        
# @lc code=end



#
# @lcpr case=start
# [[3,2],[4,3],[4,4],[2,5]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1],[2,2],[3,3],[4,4],[5,5]]\n
# @lcpr case=end

#

if __name__ == '__main__':
    s = Solution()
    s.mostPoints([[3,2],[4,3],[4,4],[2,5]])
    s.mostPoints([[1,1],[2,2],[3,3],[4,4],[5,5]]
)