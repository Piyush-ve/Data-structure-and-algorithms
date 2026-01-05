class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp, int m ,int n)
    {
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        if(i>=m or j>=n)
        {
            return INT_MAX;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int ans1=helper(i+1, j, grid, dp, m, n);
        int ans2=helper(i, j+1, grid, dp, m, n);

        return dp[i][j]=min(ans1,ans2)+grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n,-1));
        
        return helper(0, 0, grid, dp,  m, n);

    }
};