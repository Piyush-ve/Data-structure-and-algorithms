class Solution {
public:
    int rec(string s, int m, string t, int n,vector<vector<int>>&dp)
    {
        if(n<0 || (m<0 && n<0))
        {
            return 1;
        }
        if(m<0)
        {
            return 0;
        }

        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }

        if(s[m]==t[n])
        {
            int pick=rec(s,m-1,t,n-1,dp);
            int noPick=rec(s,m-1,t,n,dp);
            return dp[m][n]=pick+noPick;
        }
        else
        {
            return  dp[m][n]=rec(s,m-1,t,n,dp);
        }

    }

    int tabulation(string s, int m, string t, int n)
    {
       /*vector<vector<unsigned long long>>dp(m+1, vector<unsigned long long>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        */
        vector<unsigned long long>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=m;i++)
        {
            vector<unsigned long long>temp(n+1,0);
            temp[0]=1;
            char ch=s[i-1];
            for(int j=1;j<=n;j++)
            {
                char ch2=t[j-1];
                if(ch==ch2)
                {
                    unsigned long long  pick=dp[j-1];
                    unsigned long long  noPick=dp[j];
                    temp[j]=pick+noPick;
                }
                else
                {
                    temp[j]=dp[j];
                }
            }
            dp=temp;
        }
        return dp[n];
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();

       // vector<vector<int>>dp(m, vector<int>(n,-1));
       // return rec(s, m-1, t, n-1,dp);
       return tabulation(s, m, t, n);
    }
};