class Solution {
    public boolean isMatch(String s, String p) {
        int n=s.length();
        int m=p.length();

        boolean [][] dp = new boolean[n+1][m+1];
        dp[0][0]=true;

        for(int i=1;i<=m;i++)
        {
            if(p.charAt(i-1)=='*')
            {
            dp[0][i]=dp[0][i-2];
            }
            else
            {
                dp[0][i]=false;
            }
        }

        for(int i=1;i<=n;i++)
        {
            char ch=s.charAt(i-1);
            for(int j=1;j<=m;j++)
            {
                char ch2=p.charAt(j-1);
                if(ch==ch2 || ch2=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(ch2=='*')
                {
                    dp[i][j]=dp[i][j-2];

                    char prev=p.charAt(j-2);

                    if(prev=='.'||prev==ch)
                    {
                        dp[i][j] =  dp[i - 1][j];

                    }
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
}

/*class Solution {
public:
    bool isMatch(string s, string p) {
              int n=s.size();
        int m= p.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,false));

        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-2];
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
                if(ch==pat || pat=='.')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat=='*')
                {
                    //zero or more preeceding element
                    dp[i][j]= dp[i][j-2];

                    char prev =p[j-2];

                    if(prev=='.' || prev== ch)
                    {
                        dp[i][j]=(dp[i][j]||dp[i-1][j]);
                    }
                    
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

*/