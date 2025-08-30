class Solution {
public:
    bool find(vector<vector<int>>& matrix, int target, int k)
    {
        int i=0;
        int j=matrix[0].size()-1;

        while(i<=j)
        {
            int mid=(i+j)/2;
            if(matrix[k][mid]==target)
            {
                return true;
            }
            else if(matrix[k][mid]>target)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

       int i=0;
       int j=n-1;

       while(i<=j)
       {
           int mid=(i+j)/2;

           if(matrix[mid][0]<=target && matrix[mid][m-1]>=target)
           {
                return find(matrix,target,mid);
           }

           else if(matrix[mid][0]<=target && matrix[mid][m-1]<target)
           {
            i=mid+1;
           }
           else 
           {
             j=mid-1;
           }
       }

       return false;
    }
};