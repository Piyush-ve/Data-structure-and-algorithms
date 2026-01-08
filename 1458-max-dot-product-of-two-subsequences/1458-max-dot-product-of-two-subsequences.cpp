class Solution {
public:
    int helper(int i, int j, int m, int n,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp, int &ans)
    {
        if(i>=m || j>=n)
        return -1e9;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int take=(nums1[i]*nums2[j])+ max(0,helper(i+1,j+1,m,n,nums1,nums2,dp,ans));
        int b=helper(i,j+1,m,n,nums1, nums2,dp,ans);
        int c=helper(i+1,j,m, n, nums1, nums2,dp,ans);
        int d=helper(i+1,j+1,m,n,nums1,nums2,dp,ans);

        dp[i][j]=max(take,max(b,max(c,d)));

        ans=max(dp[i][j],ans);
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;

        int m= nums1.size();
        int n=nums2.size();
        int ans=INT_MIN;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        helper(i,j,m,n,nums1,nums2,dp,ans);

        return ans;


        
    }
};