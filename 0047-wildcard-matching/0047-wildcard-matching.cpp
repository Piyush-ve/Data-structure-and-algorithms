class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m= p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,false));

        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-1];
            else
            {
                dp[0][i]=false;
            }
        }


        for(int i=1;i<=n;i++)
        {
            char ch=s[i-1];
            for(int j=1;j<=m;j++)
            {
                char pat=p[j-1];
                if(ch==pat || pat=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat=='*')
                {
                    dp[i][j]=(dp[i-1][j-1]||dp[i-1][j]||dp[i][j-1]);
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];

    }
};