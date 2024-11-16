#
# @lc app=leetcode.cn id=3249 lang=python3
# @lcpr version=30204
#
# [3249] 统计好节点的数目
#


# @lcpr-template-start
from operator import truediv
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
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        # 题目核心：如何把无向的边，转为以0为根的树。需要通过bds建树
        n = len(edges) + 1
        # em = [[False for i in range(n)] for i in range(n)] # 用二维数组表示节点之间的连通性
        tree = [[] for i in range(n)]
        for p, c in edges:
            # em[p][c], em[c][p] = True, True
            tree[p].append(c)
            tree[c].append(p)
       
        # roots = [0]
        # vis = [False] * n
        # while len(roots) > 0 :
        #     root = roots.pop()
        #     vis[root] = True
        #     for i, ok in enumerate(em[root]):
        #         if ok and not vis[i] :
        #             roots.insert(0, i)
        #             tree[root].append(i)

        # isGood = [True] * n
        value = [1] * n # 记录每个节点以自己为根的子树有多少节点
        self.ans = 0

        def dfs(root: int, parent: int):
            children = []
            for i in tree[root]:
                if i != parent:
                    children.append(i)

            if len(children) == 0: # 该节点没有子节点了，是好节点
                # isGood[root] = True
                self.ans += 1
                return

            for child in children:
                dfs(child, root)
                value[root] += value[child]
            
            target = value[children[0]]
            for child in children:
                if value[child] != target:
                    # isGood[root] = False
                    return
            # isGood[root] = True
            self.ans += 1
            return
        dfs(0, 0)
        return self.ans
                


        
# @lc code=end



#
# @lcpr case=start
# [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]\n
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().countGoodNodes([[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]))
    print(Solution().countGoodNodes([[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]))
    print(Solution().countGoodNodes([[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]))
    print(Solution().countGoodNodes([[6,0],[1,0],[5,1],[2,5],[3,1],[4,3]]))