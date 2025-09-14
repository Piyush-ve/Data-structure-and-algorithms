class Solution {
public:
    int m;
    int n;
    vector<pair<int,int>>edges={{-1,0},{0,-1},{1,0},{0,1}};

    void helper(int i, int j,  vector<vector<bool>>&vis, vector<vector<char>>& grid)
    {
        for(auto it : edges)
        {
            int newI=it.first+i;
            int newJ=it.second+j;

            if(newI<m && newI>=0 && newJ<n && newJ>=0 && grid[newI][newJ]=='1' && vis[newI][newJ]==false)
            {
                vis[newI][newJ]=true;
                
                helper(newI, newJ , vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q; //{i,j}
        m=grid.size();
        n=grid[0].size();
         for(int i=-0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    q.push({i,j});
                }
            }
         }

         vector<vector<bool>>vis(m,vector<bool>(n,false));
        int island=0;
         while(!q.empty())
         {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(vis[i][j]==false)
            {
                vis[i][j]=true;
                island++;
                helper(i, j, vis, grid);
                
            }
            

         }

         return island;

    }
};