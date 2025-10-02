class Solution {
public:
    int rec(int i, vector<int>&prices, int n, int buy, vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        return dp[i][buy];

        if(buy)
        {
            int Buy=rec(i+1,prices,n,0,dp)-prices[i];
            int notBuy=rec(i+1,prices,n,1,dp);

            return dp[i][buy]=max(Buy,notBuy);
        }
        else
        {
            int sell=rec(i+2,prices,n,1,dp)+prices[i];
            int notsell=rec(i+1,prices,n,0,dp);

            return dp[i][buy]=max(sell,notsell);
        }


    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
    
        return rec(0,prices,n,1,dp);
    }
};