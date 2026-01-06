class Solution {
public:
    bool helper(string s, int i, int j, vector<vector<int>>&dp)
    {
        if(i>=j)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=helper(s,i+1,j-1,dp);
        }
        else
        {
            return dp[i][j]=false;
        }
    }
    string longestPalindrome(string s) {
        int n= s.size();
        int ans=0;
        int idx=0;
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(helper(s,i,j,dp))
                {
                    if(ans<(j-i+1))
                    {
                        idx=i;
                        ans=(j-i+1);
                    }
                }

            }
        }
        return s.substr(idx,ans);
    }
};