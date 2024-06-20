#
# @lc app=leetcode.cn id=125 lang=python3
# @lcpr version=30204
#
# [125] 验证回文串
#


# @lcpr-template-start
from typing import List, ClassVar, Dict, Optional
class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next
# @lcpr-template-end
# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        newStr = "".join(map(lambda x: x.lower() if x.isalpha() or x.isdigit() else "", s))
        # print(newStr)
        # print("".join(reversed(newStr)))
        return newStr == "".join(reversed(newStr))
# @lc code=end



#
# @lcpr case=start
# "A man, a plan, a canal: Panama"\n
# @lcpr case=end

# @lcpr case=start
# "race a car"\n
# @lcpr case=end

# @lcpr case=start
# " "\n
# @lcpr case=end

# @lcpr case=start
# "0P"\n
# @lcpr case=end

#

