bool rec(int n, int k, vector<int> &arr, int curr, vector<vector<int>>&dp)
{
    if(curr==k)
    {
        return true;
    }
    if(n<0 || curr>k)
    {
        return false;
    }
    

    if(dp[n][curr]!=-1)
    {
        return dp[n][curr];
    }

    int val=arr[n];

    if(val+curr<=k)
    {
        bool op1=rec(n-1, k, arr, val+curr, dp);//picking
        bool op2=rec(n-1, k, arr, curr, dp);//not picking

        return dp[n][curr]=op1||op2;
    }
    else
    {
        return dp[n][curr]=rec(n-1, k, arr, curr,dp);//not picking
    }

}
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        // Write your code here.
	int target=0;
    int n=arr.size();
	for(int i=0;i<n;i++)
	{
		target+=arr[i];
	}

    if(target%2!=0)
    return false;

	target=target/2;

	vector<vector<int>>dp(n,vector<int>(target+1,-1));

	return rec(n-1, target, arr, 0, dp);
    }
};