class Solution {
public:
    int findMax(vector<int>nums)
    {
        int idx=0;
        int Max=nums[0];

        for(int i=0;i<nums.size();i++)
        {
           if(Max<nums[i])
           {
                Max=nums[i];
                idx=i;
           }
        }

        return idx;

    }
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        if(nums.size()==1)
        {
            int j=findMax(nums[0]);
            return {0,j};
        }

        int l=findMax(nums[0]);

        if(nums[0][l]>nums[1][l])
        {
            return {0,l};
        }
        
        int n=nums.size();
        int k=findMax(nums[n-1]);


        if(nums[n-1][k]>nums[n-2][k])
        {
            return {n-1,k};
        }


        int i=1;
        int j=nums.size()-2;

        while(i<=j)
        {
            int mid=(i+j)/2;

            int k=findMax(nums[mid]);

            if(nums[mid-1][k]<nums[mid][k] && nums[mid][k]>nums[mid+1][k])
            {
                return {mid,k};
            }
            else if(nums[mid][k]<nums[mid][k+1])
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }

        return {-1,-1};
    }
};