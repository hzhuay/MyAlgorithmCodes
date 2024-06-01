class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        def contains(a: dict, b: dict) -> bool:
            for k, v in b.items():
                if k not in a:
                    return False
                elif a[k] < v:
                    return False
            return True

        count = {}
        target = {}
        for c in t:
            target[c] = target.get(c, 0) + 1
        l, r = 0, 0
        n = len(s)
        ansLeft, ansLen = -1, n
        while r < n:
            c = s[r]
            count[c] = count.get(c, 0) + 1
            # print(f"Before {c} {count} {target} {contains(count, target)} {ansLeft} {ansLen}")
            while contains(count, target) and l <= r:
                # print(ansLen < r - l + 1)
                if ansLen >= r - l + 1:
                    ansLen = r - l + 1
                    ansLeft = l
                count[s[l]] -= 1
                l += 1
            # print(f"After {c} {count} {target} {contains(count, target)} {ansLeft} {ansLen}\n")
            r += 1
        return "" if ansLeft == -1 else s[ansLeft:ansLeft+ansLen]
                
if __name__ == "__main__":
    print(Solution().minWindow("ADOBECODEBANC", "ABC"))
