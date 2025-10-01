class Solution {
public:
   int rec(vector<int>& prices,int i, int n, int buy, int tran, vector<vector<vector<int>>>&dp)
    {
        if(i==n || tran>=2)
        {
            return 0;
        }
        if(dp[i][buy][tran]!=-1)
        {
            return dp[i][buy][tran];
        }
        if(buy)
        {
            //it has two options ya to sell it ya fir find another minimum element to buy it
           int Buy=rec(prices,i+1,n,0,tran,dp)-prices[i];
           int notBuy=rec(prices,i+1,n,1,tran,dp);

           return dp[i][buy][tran]=max(Buy,notBuy);
        }
        
        else
        {
            int sell=rec(prices,i+1,n,1,tran+1,dp)+prices[i];
            int notSell=rec(prices,i+1,n,0,tran,dp);
           
            return dp[i][buy][tran]=max(sell,notSell);
        }

      


    }
    int maxProfit(vector<int>& prices) {
       
       int n=prices.size();
       int tran=0;
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return rec(prices,0,prices.size(),1,tran,dp);


    }
    
};

