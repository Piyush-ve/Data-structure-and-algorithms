class Solution {
public:
    int rec(string word1,int n, string word2, int m,  vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return m;
        }
        if(m==0)
        {
            return n;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(word1[n-1]==word2[m-1])
        {
            return dp[n][m]= rec(word1, n-1, word2, m-1,dp);
        }
        else
        {
            int ans1=rec(word1, n, word2, m-1,dp)+1;
            int ans2=rec(word1, n-1, word2, m,dp)+1;
            int ans3=rec(word1, n-1, word2, m-1,dp)+1;

            return dp[n][m]=min(ans1, min(ans2, ans3));
        }
    }

    int tab(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));


        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }

        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];//similar
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;  //delete dp[i-1][j]   // replcae dp[i-1][j-1]  //insert dp[i][j-1]
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));


      return rec(word1, n, word2, m, dp);
    }
};