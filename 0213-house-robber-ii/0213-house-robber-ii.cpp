class Solution {
public:
    int tab(int curr,vector<int>&nums,int n)
    {
        
        vector<int>dp(n+1,0);
        dp[curr]=nums[curr];

        for(int i=curr+1;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=dp[i-2];
            }
            int skip=dp[i-1];

            dp[i]=max(take,skip);
        }

        return dp[n-1];
    }
//memoization
    int solve(int curr,vector<int>&nums,int n,vector<int>&dp)
    {
        if(curr>=n)
        {
            return 0;
        }
        if(dp[curr]!=-1)
        return dp[curr];

        int rob= nums[curr]+solve(curr+2,nums,n,dp);

        int skip=solve(curr+1,nums,n,dp);

        return dp[curr]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();

        if(n==0)return 0;
        if(n==1)return nums[0];

        vector<int>dpl(n,-1);

      //  int lastEleIncl=solve(1,nums,n,dpl);

        vector<int>dpf(n,-1);
      //  int firstEleIncl=solve(0,nums,n-1,dpf);


     //  return max(lastEleIncl,firstEleIncl);

     int l=tab(1,nums,n);
     int f=tab(0,nums,n-1);

     return max(l,f);
    }
};