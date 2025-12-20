class Solution(object):
    def helper(self, cost,n):
        if(n==0 or n==1):
            return 0
        
        if(self.dp[n]!=-1):
            return self.dp[n]
        
        self.dp[n]=min(
            self.helper(cost,n-1)+cost[n-1],
            self.helper(cost,n-2)+cost[n-2]
        )
        return self.dp[n]
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n=len(cost)
        self.dp = [-1]*(n+1)

        self.helper(cost,n)
        return self.dp[n]

        