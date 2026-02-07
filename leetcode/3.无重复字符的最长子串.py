#
# @lc app=leetcode.cn id=3 lang=python3
# @lcpr version=30204
#
# [3] 无重复字符的最长子串
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
    def lengthOfLongestSubstring(self, s: str) -> int:
        vis = {}
        n = len(s)
        l, r = 0, 1
        ans = 0
        for r in range(1, n+1):
            # 只要s[r-1]还没见过，则r可以继续向右
            char = s[r-1]
            if char in vis and vis[char] == True:
                while vis[char] :
                    vis[s[l]] = False
                    l += 1
            vis[char] = True
            ans = max(ans, r-l)
            # print(s[l:r])
                
        return ans
                

                            
# @lc code=end



#
# @lcpr case=start
# "abcabcbb"\n
# @lcpr case=end

# @lcpr case=start
# "bbbbb"\n
# @lcpr case=end

# @lcpr case=start
# "pwwkew"\n
# @lcpr case=end

#

if __name__ == "__main__":
    s = Solution()
    print(s.lengthOfLongestSubstring("abcabcbb"))