# @lcpr-before-debug-begin
from typing import *
# @lcpr-before-debug-end

#
# @lc app=leetcode.cn id=28 lang=python3
# @lcpr version=30204
#
# [28] 找出字符串中第一个匹配项的下标
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
    def strStr(self, main: str, sub: str) -> int:
        def build(sub: str) -> list:
            pre = 0 # 当前遍历到的sub[:i]子串中，共同前后缀的长度
            nextval = [0] # 首字符默认是0
            i = 1
            while i < len(sub):
                if sub[pre] == sub[i]: # sub[i-pre:i]==sub[:pre]，继续向后匹配
                    pre += 1
                    nextval.append(pre)
                    i += 1
                elif pre == 0: # 当前没有匹配的前后缀，直接继续遍历
                    nextval.append(0)
                    i += 1
                else: # 虽然当前遍历的sub[i]不匹配，但是之前有部分匹配
                    # 要在sub[:pre]内重新尝试匹配
                    pre = nextval[pre - 1]
            return nextval

        nextval = build(sub) # 定义：nextval[i]为sub[:i]中从sub头尾两端的最长相同前后缀
        # 如sub="ababc"，则next=[0,0,1,2,0]。
        # 这样当匹配失败时，可以跳过子串的部分前缀，从中间开始匹配
        print(nextval)
        
        i, j = 0, 0 # i为主串下标，j为子串下标
        while i < len(main):
            if main[i] == sub[j]: # 匹配成功时，2个下标都继续
                i += 1
                j += 1
            elif j > 0: 
                # 匹配失败时，如果是部分失败，需要尽量保留从最长的相同前缀开始重新匹配 
                j = nextval[j - 1] # 此时直到前一个字符为止都是匹配的。跳到子串开头有相同前缀的地方
            else: # 子串第一个字符就不匹配，主串继续遍历
                i += 1

            if j == len(sub): # 当j到子串的末尾，说明匹配成功
                return i - j
        return -1

# @lc code=end



#
# @lcpr case=start
# "sadbutsad"\n"sad"\n
# @lcpr case=end

# @lcpr case=start
# "leetcode"\n"leeto"\n
# @lcpr case=end

# @lcpr case=start
# "aaaaa"\n"bba"\n
# @lcpr case=end

#

if __name__=="__main__":
    Solution().strStr("aaaaa", 'bba')
    Solution().strStr("ABABABCAA", 'ABABC')