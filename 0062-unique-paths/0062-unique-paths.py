class Solution(object):
    def helper(self,m,n):
        if(m<0 or n<0):
            self.dp[m][n]=0
            return 0
        
        if(m==0 or n==0):
            self.dp[m][n]=1
            return 1

        if(self.dp[m][n]!=-1):
            return self.dp[m][n]

        ans1=self.helper(m-1,n)
        ans2= self.helper(m,n-1)

        self.dp[m][n]=ans1+ans2

        return self.dp[m][n]

    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        self.dp=[[-1 for _ in range(n)]for _ in range(m)]

        self.helper(m-1,n-1)
        return self.dp[m-1][n-1]
        