class Solution {
public:
 int M=1e9 +7;
    int rec(string s, int n,vector<unsigned int>&dp)
    {
        if(n<0)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        unsigned int pick=rec(s,n-1,dp)%M;
        int noPick=rec(s,n-1,dp)%M;

        for (int j = n - 1; j >= 0; j--) {
        if (s[j] == s[n]) {
            pick -= rec(s, j - 1,dp);
            break;
            }
        }

        return dp[n]=(pick + noPick + M) % M;

       
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<unsigned int>dp(n,-1);
        return rec(s,n-1,dp)-1;
    }
};