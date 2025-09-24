class Solution {
public:
    int helper(vector<int>& nums, int i, int n,  vector<int>&dp)
    {
        if(i>=n-1)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int Min=INT_MAX;

        for(int j=1;j<=nums[i];j++)
        {
            //Min=min(Min,helper(nums, i+j, n, jumps+1,dp));
            int next = helper(nums, i + j, n, dp);
            if (next != INT_MAX) {
                Min = min(Min, 1 + next);
            }
        }
        return dp[i]=Min;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return helper(nums, 0, nums.size(), dp);
    }
};