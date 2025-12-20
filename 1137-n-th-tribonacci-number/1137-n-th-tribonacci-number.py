class Solution(object):

    def helper(self, n):
        if( n==1 or n==2):
            return 1
        elif(n==0):
            return 0
        
        if(self.dp[n]!=-1):
            return self.dp[n]

        self.dp[n]=self.helper(n-1) + self.helper(n-2) + self.helper(n-3)
        return self.dp[n]

    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.dp=[-1]*(n+1)
        return self.helper(n)