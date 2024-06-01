class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        n = len(nums)
        ans = nums[0]
        tmp =  nums[0]
        for i in nums[1:]:
           tmp += i
           tmp = max(tmp, i)
           ans = max(ans, tmp)
        return ans