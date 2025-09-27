class Solution {
public:
    int rec(int n, vector<int>& arr, int s1, vector<vector<int>>&dp)
{
    if (n == 0) {
        if (s1 == 0 && arr[0] == 0) return 2;  // either take or not take 0
        if (s1 == 0 || s1 == arr[0]) return 1;
        return 0;
    }
    if(dp[n][s1]!=-1)
    {
        return dp[n][s1];
    }
    int val=arr[n];

    if((s1-val)>=0)
    {
        int pick=rec(n-1,arr,s1-val,dp);
        int noPick=rec(n-1, arr, s1,dp);

        return dp[n][s1]=(pick+noPick);
    }
    else
    {
        return dp[n][s1]=rec(n-1, arr, s1,dp);
    }
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int target=0;

    for(int i=0;i<n;i++)
    {
        target+=arr[i];
    }

    if(target<d || (target-d)%2!=0)
    return 0;

    int newTarget=(target-d)/2;

    vector<vector<int>>dp(n, vector<int>(newTarget+1,-1));

    return rec(n-1,arr,newTarget,dp);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};