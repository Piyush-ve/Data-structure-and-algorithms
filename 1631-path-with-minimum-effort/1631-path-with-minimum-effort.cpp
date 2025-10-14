class Solution {
public:
    vector<pair<int,int>>gr={{-1,0},{1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& grid) {

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        
        ans[0][0]=0;
        
        pq.push({0,0,0});
        
        while(!pq.empty())
        {
            vector<int>topp=pq.top();
            pq.pop();
            
            int dis=topp[0];
            int i=topp[1];
            int j=topp[2];

            int ele=grid[i][j];
            
            for(auto it: gr)
            {
                int new_i=i+it.first;
                int new_j=j+it.second;
                
                if(new_i>=0 && new_i <n && new_j>=0 && new_j<m)
                {
                    int currDist=abs(grid[i][j]-grid[new_i][new_j]);
                    currDist=max(dis, currDist);
                    
                   
                    
                    if(ans[new_i][new_j]>currDist)
                    {
                        ans[new_i][new_j]=currDist;
                        pq.push({currDist,new_i, new_j});
                    }
                    
                    
                }
            }
        }
        return ans[n-1][m-1];
        
    }
};