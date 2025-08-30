class Solution {
public:
    int find(vector<int>& nums) {
        
        if(nums.size()==1)
        return 0;

        if(nums[0]>nums[1])
        return 0;

        if(nums[nums.size()-1]> nums[nums.size()-2])
        return nums.size()-1;
        int i=1;
        int j=nums.size()-2;

        while(i<=j)
        {
            int mid=(i+j)/2;

            if(nums[mid]>nums[mid-1] && nums[mid+1]<nums[mid])
            {
                return mid;
            }
            else if(nums[mid]<nums[mid+1])
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return -1;
    }



    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int i=0;
      int n=mat.size();
      
      while(i<n)
      {
        int a=find(mat[i]);

            if(i-1>=0 && i+1<n)
            {
                if(mat[i-1][a]<mat[i][a] && mat[i+1][a]<mat[i][a])
                {
                    return{i,a};
                }
            }
            else if(i-1>=0)
            {
                if(mat[i-1][a]<mat[i][a] )
                {
                    return{i,a};
                }
            }
            else if(i+1<n)
            {
                if(mat[i+1][a]<mat[i][a] )
                {
                    return{i,a};
                }
            }
            else
            {
                return {i,a};
            }
            i++;
        }
        
      

    return {-1, -1};



    }
};