class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        m, d, i, j, ans = max(nums), deque([]), -1, 0, 0
        for j in range(len(nums)):
            if nums[j] == m:
                d.append(j)
                if len(d) == k:
                    tmp = i
                    i = d.popleft()
                    ans = ans + (len(nums)-j) * (i-tmp)
        return ans