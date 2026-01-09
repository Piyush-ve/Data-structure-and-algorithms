class Solution {
    public int helper(int i, int n, int[] nums, int[]dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
       
            int take= helper(i+2,n,nums,dp)+nums[i];
            int notTake= helper(i+1,n,nums,dp);

        return dp[i]=Math.max(take,notTake);
        
    }
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==1)return nums[0];
        int []dp0=new int[n];
        Arrays.fill(dp0,-1);

        int []dp1=new int[n];
        for(int i=0;i<n;i++)
        {
            dp1[i]=-1;
        }

        int inclFirst=helper(0,n-1,nums,dp0);
        int exclFirst=helper(1,n,nums,dp1);

        return Math.max(inclFirst,exclFirst);

    }
}