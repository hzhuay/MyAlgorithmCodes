#
# @lc app=leetcode.cn id=712 lang=python3
# @lcpr version=30204
#
# [712] 两个字符串的最小ASCII删除和
#

# @lc code=start
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        # 这道题相比最长公共子序列，关注的不再是长度，而是要公共子序列的ascii值尽量大，这样删掉的值最小
        # 其实更类似编辑距离
        n, m = len(s1), len(s2)
        # dp[i][j]表示s1[:i-1]和s2[:j-1]的最小编辑值
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        # 初始化
        for i in range(1, n + 1):
            # 当s2为空串时，需要把s1删完
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
        for j in range(1, m + 1):
            # 当s1为空串时，需要把s2删完
            dp[0][j] = dp[0][j - 1] + ord(s2[j - 1])
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    # 如果不通，则要么删除s1[i-1]或者s2[j-1]
                    dp[i][j] = min(dp[i-1][j] + ord(s1[i-1]), dp[i][j-1] + ord(s2[j-1]))
        return dp[-1][-1]
        
# @lc code=end



#
# @lcpr case=start
# "sea"\n"eat"\n
# @lcpr case=end

# @lcpr case=start
# "delete"\n"leet"\n
# @lcpr case=end

#

