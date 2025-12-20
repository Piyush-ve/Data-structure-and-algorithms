class Solution(object):
    def helper(self, text1, n, text2, m):
        if(n<0 or m<0):
            return 0
        
        if(self.dp[n][m]!=-1):
            return self.dp[n][m]

        if(text1[n]==text2[m]):
            self.dp[n][m]=self.helper(text1,n-1,text2,m-1)+1
        else:
            self.dp[n][m]=max(
                self.helper(text1,n,text2,m-1),
                self.helper(text1,n-1,text2,m),
            )
        
        return self.dp[n][m]

    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        n=len(text1)
        m=len(text2)
        self.dp=[[-1 for _ in range(m)]for _ in range(n)]

        self.helper(text1,n-1,text2,m-1)
        return self.dp[n-1][m-1]


        


        
        