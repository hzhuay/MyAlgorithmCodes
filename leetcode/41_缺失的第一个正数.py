class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        mark = [False for i in range(100001)]
        for i in nums:
            if 0 <= i and i <= 100000:
                mark[i] = True
        for i in range(1, 100001):
            if not mark[i]:
                return i
        return 100001