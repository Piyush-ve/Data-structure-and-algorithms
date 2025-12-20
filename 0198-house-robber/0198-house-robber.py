class Solution(object):
    def helper(self, nums, n):
        if(n<0):
            return 0
        
        if(self.dp[n]!=-1):
            return self.dp[n]


        self.dp[n]=max(
            self.helper(nums,n-2)+nums[n],
            self.helper(nums,n-1)
        )


        return self.dp[n]

        
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        self.dp=[-1]*(n)

        self.helper(nums,n-1)
        return self.dp[n-1]
