class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       vector<vector<int>>ans(n,vector<int>(n,0));

       //for bottom left
       for(int i=0;i<n;i++)
       {
            vector<int>a;
            int k=i;
            for(int j=0;j<n;j++)
            {
                if(k>=n || j>=n)
                {
                    break;
                }
                a.push_back(grid[k][j]);
                k++;
            }
            sort(a.begin(),a.end(),greater<>());
            
            k=i;
            for(int j=0;j<n;j++)
            {
                if(k>=n || j>=n)
                {
                    break;
                }
                ans[k][j]=a[j];
                k++;
            }
            
       }
        //upper right
        for(int i=1;i<n;i++)
       {
            vector<int>a;
            int k=i;
            for(int j=0;j<n;j++)
            {
                if(k>=n || j>=n)
                {
                    break;
                }
                a.push_back(grid[j][k]);
                k++;
            }
            sort(a.begin(),a.end());
            
            k=i;
            for(int j=0;j<n;j++)
            {
                if(k>=n || j>=n)
                {
                    break;
                }
                ans[j][k]=a[j];
                k++;
            }
            
       }

     

       return ans;



    }
};