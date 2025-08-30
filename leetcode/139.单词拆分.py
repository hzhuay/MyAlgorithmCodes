#
# @lc app=leetcode.cn id=139 lang=python3
# @lcpr version=30204
#
# [139] 单词拆分
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
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [True] + [False] * n # dp[i]表示s[0..i-1]能否被拆分成字典中的单词
        # 由于wordDict的长度最大1000，s的长度最大300，因此与其判断wordDict内的单词是否在s内，不如判断s的子串是否在wordDict内
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] == True and s[j:i] in wordDict: # 如果s[0..j-1]能被拆分，且s[j..i-1]在字典中
                    dp[i] = True    # 则s[0..i-1]能被拆分
                    break
        return dp[-1]
        
# @lc code=end 

#
# @lcpr case=start
# "leetcode"\n["leet", "code"]\n
# @lcpr case=end

# @lcpr case=start
# "applepenapple"\n["apple", "pen"]\n
# @lcpr case=end

# @lcpr case=start
# "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
# @lcpr case=end

#

