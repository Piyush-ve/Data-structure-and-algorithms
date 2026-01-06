class Solution {
public:
    bool helper(string s1, string s2, string s3, int i,int j, int k, vector<vector<int>>&dp)
    {
        int n=s3.size();
        int m=s1.size();
        int p=s2.size();

        if(k>=n)
        {
            return true;
        }
        if(i==m && j==p)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool a1=false;
        bool a2=false;

        if(i<m && s1[i]==s3[k])
        {
            a1= helper(s1,s2,s3,i+1,j,k+1,dp);
        }

        if(j<p && s2[j]==s3[k])
        {
            a2= helper(s1,s2,s3,i,j+1,k+1,dp);
        }

        return dp[i][j]=a1||a2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i=0;
        int j=0;
        int k=0;

        int m=s1.size();
        int n=s2.size();

        if((s1.size()+ s2.size()) != s3.size())
        {
            return false;
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return helper(s1,s2,s3,i,j,k,dp);
    }
};