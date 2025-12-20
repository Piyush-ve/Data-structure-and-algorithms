class Solution(object):
    def helper(self, n):
        if(n==0 or n==1):
            self.dp[n]=1
            return 1

        if(n==2):
            self.dp[n]=n
            return n
        
        if(self.dp[n]!=-1):
            return self.dp[n]

        self.dp[n]=2*self.helper(n-1)+self.helper(n-3)

        return self.dp[n]        

    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        self.dp=[-1]*(n+1)

        self.helper(n)
        return self.dp[n]
        