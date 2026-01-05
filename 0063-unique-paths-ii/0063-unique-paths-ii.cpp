class Solution {
public:
    int helper(vector<vector<int>>& obstaclesGrid, vector<vector<int>>& dp, int i, int j, int m , int n)
    {
        if(i==m && j==n)
        {
            return 1;
        }

        if(i>m or j>n)
        {
            return 0;
        }

        if(obstaclesGrid[i][j]==1)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int a=helper(obstaclesGrid, dp, i+1, j, m ,n);
        int b=helper(obstaclesGrid, dp, i, j+1, m, n);

        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(obstacleGrid, dp, 0, 0, m-1, n-1);

    }
};