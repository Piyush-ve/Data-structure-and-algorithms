class Solution {
public:

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();

        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

        dp[0][0]=true;

        for(int i=1;i<=n;i++)
        {
            if(p[i-1]=='*' && dp[0][i-1]==true)
            {
                dp[0][i]=true;
            }

        }

        for(int i=1;i<=m;i++)
        {
            char ch=s[i-1];
            for(int j=1;j<=n;j++)
            {
                char pCh=p[j-1];
                if(ch==pCh || pCh=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pCh=='*')
                {
                    dp[i][j]=(dp[i-1][j-1] || dp[i][j-1] ||dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[m][n];
    }
};