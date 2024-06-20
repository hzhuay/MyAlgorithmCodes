#
# @lc app=leetcode.cn id=347 lang=python3
# @lcpr version=30204
#
# [347] 前 K 个高频元素
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
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import defaultdict
        N = 100005
        bucket = [[] for i in range(N)]
        count = defaultdict(int)
        for i in nums:
            count[i] += 1

        for key, val in count.items():
            bucket[val].append(key)
        ans = []
        for i in range(100000, 0, -1):
            ans = ans + bucket[i]
            if len(ans) >= k:
                break
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,1,1,2,2,3]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n2\n
# @lcpr case=end

