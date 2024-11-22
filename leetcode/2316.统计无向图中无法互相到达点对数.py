#
# @lc app=leetcode.cn id=2316 lang=python3
# @lcpr version=30204
#
# [2316] 统计无向图中无法互相到达点对数
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
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
class Dsu:
    def __init__(self, size: int):
        self.pa = list(range(size))
    
    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    # 合并函数，将x合并到y
    def union(self, x, y):
        self.pa[self.find(x)] = self.find(y)

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        dsu = Dsu(n)
        for edge in edges:
            a, b = edge
            dsu.union(a, b)
        count = {}
        for i in range(n):
            tmp = dsu.find(i)
            if dsu.find(i) not in count:
                count[tmp] = 1
            else:
                count[tmp] += 1
        ans = 0
        print(count)
        for i in count.values():
           ans += i * (n - i)
        return ans // 2
        
# @lc code=end



#
# @lcpr case=start
# 3\n[[0,1],[0,2],[1,2]]\n
# @lcpr case=end

# @lcpr case=start
# 7\n[[0,2],[0,5],[2,4],[1,6],[5,4]]\n``
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().countPairs(3, [[0,1],[0,2],[1,2]]))
    print(Solution().countPairs(7, [[1,6],[5,4],[0,2],[0,5],[2,4]]))
