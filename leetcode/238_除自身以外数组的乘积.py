class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        # 双向前缀和
        leftPre = [1 for i in range(n+1)]
        rightPre = [1 for i in range(n+1)]
        for i in range(n):
            leftPre[i+1] = leftPre[i] * nums[i]
        for i in range(n-1, -1, -1):
            rightPre[i-1] = rightPre[i] * nums[i]
        ans = [0 for i in range(n)]
        print(leftPre)
        print(rightPre)
        for i, v in enumerate(nums):
            ans[i] = leftPre[i] * rightPre[i]
        return ans
    
if __name__ == "__main__":
    print(Solution().productExceptSelf([-1,1,0,-3,3]))