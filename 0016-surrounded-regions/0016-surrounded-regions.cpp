class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>> &mat)
    {
        vis[r][c]=1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(auto dir:directions)
        {
            int nr=dir[0]+r;
            int nc=dir[1]+c;
            
            if(nr>=0&& nc>=0&& nr<n &&nc<m && mat[nr][nc]=='O' && !vis[nr][nc])
            {
                dfs(nr,nc,vis,mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traversing boundaries
        
        //row
        for(int i=0;i<m;i++)
        {
            
            if(mat[0][i]=='O' && !vis[0][i])//first row
            {
                dfs(0,i,vis,mat);
            }
            
            if(mat[n-1][i]=='O' && !vis[n-1][i])//first col
            {
                dfs(n-1,i,vis,mat);
            }
        }
        
        //col
        
        for(int i=0;i<n;i++)
        {
            
            if(mat[i][0]=='O'&& !vis[i][0])
            {
                dfs(i,0,vis,mat);
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1])
            {
                dfs(i,m-1,vis,mat);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    mat[i][j]='X';
                }
            }  
        }
        return ;
    }
};