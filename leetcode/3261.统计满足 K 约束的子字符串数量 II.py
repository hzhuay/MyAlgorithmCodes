#
# @lc app=leetcode.cn id=3261 lang=python3
# @lcpr version=30204
#
# [3261] 统计满足 K 约束的子字符串数量 II
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
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        # 前缀和，pre[i]表示s[:i]累计多少0和1
        n = len(s)
        pre = [0] * (n + 1) # 记录s[:i]有多少子串符合k约束
        cnt = [0, 0] # 记录当前0和1的数量
        nxt = [n] * n # nxt[i]记录i往右第一个不满足k约束的下标
        l, r = 0, 0
        for r in range(n):
            cnt[int(s[r])] += 1
            while cnt[0] > k and cnt[1] > k: # 不满足k约束时，窗口左边界右移
                nxt[l] = r
                cnt[int(s[l])] -= 1
                l += 1
            
            # 此时的l和r正好满足k约束
            # pre[r + 1]相较于pre[r]，新增了s[r]这个字符带来的新子串
            pre[r + 1] = pre[r] + (r - l + 1)
        ans = []
        for l, r in queries:
            # 右边界是nxt[l]，或者s[l:r]都符合k，则为 r + 1
            upper = min(nxt[l], r + 1)
            # s[l:upper]内符合约束的数量
            leftNum = (upper - l + 1) * (upper - l) // 2
            # s[upper:r]内符合约束的数量
            rightNum = pre[r + 1] - pre[upper]
            ans.append(leftNum + rightNum)
        return ans
        
# @lc code=end



#
# @lcpr case=start
# "0001111"\n2\n[[0,6]]\n
# @lcpr case=end

# @lcpr case=start
# "010101"\n1\n[[0,5],[1,4],[2,3]]\n
# @lcpr case=end

#

if __name__=='__main__':
    print(Solution().countKConstraintSubstrings( "0001111", 2, []))
