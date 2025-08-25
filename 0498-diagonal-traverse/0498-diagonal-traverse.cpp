class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0;
        int j=0;

        int n=mat.size();
        int m=mat[0].size();

        bool up=true;

        vector<int> v;

    //    vector<vector<bool>>vis(n,vector<bool>(m, false));

        while((i<n && i>=0) && (j>=0 && j<m))
        {
            if((i<n && i>=0) && (j>=0 && j<m))
            {
                v.push_back(mat[i][j]);
              //  vis[i][j]=true;
            }

            if(up)
            {
               // i=i-1;
                //j=j+1;

                if((i-1<n && i-1>=0) && (j+1>=0 && j+1<m))
                {
                    i=i-1;
                    j=j+1;
                    
                }
                else
                {
                    up =false;

                    if(j+1<m )
                    {
                        j=j+1;
                    }
                    else
                    {
                        i=i+1;
                    }
                }
            }
            else 
            {
              //  i=i+1;
              //  j=j-1;


                if((i+1<n && i+1>=0) && (j-1>=0 && j-1<m))
                {
                    i=i+1;
                    j=j-1;
                }
                else
                {
                    up =true;

                    if(i+1<n )
                    {
                        i=i+1;
                    }
                    else
                    {
                        j=j+1;
                    }
                }
            }
        }
        return v;
    }
};