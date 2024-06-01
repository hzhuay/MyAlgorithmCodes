class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        # 按左区间排序
        intervals.sort(key=lambda x: x[0])
        ans = []
        tmp = []
        n = len(intervals)
        for i in range(n):
            if tmp == []:
                tmp = intervals[i]
            elif tmp[1] >= intervals[i][0]:
                if tmp[1] < intervals[i][1]:
                    tmp[1] = intervals[i][1]
            else:
                ans.append(tmp)
                tmp = intervals[i]
        if tmp != []:
            ans.append(tmp)
        return ans