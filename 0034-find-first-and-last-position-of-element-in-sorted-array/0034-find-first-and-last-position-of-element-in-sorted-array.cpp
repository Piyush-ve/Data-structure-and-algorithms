class Solution {
public:
    int lastSearch(vector<int>& nums, int target)
    {
        int i=0;
        int j=nums.size()-1;

        int idx=-1;

        while(i<=j)
        {
            int mid=(i+j)/2;

            if(nums[mid]<=target)
            {
                i=mid+1;
                if(nums[mid]==target)
                {
                    idx=mid;
                }
                
            }
            else if(nums[mid]>target)
            {
                j=mid-1;
            }
            
        }
        return idx;
    }

    int firstSearch(vector<int>& nums, int target)
    {
        int i=0;
        int j=nums.size()-1;

        int idx=-1;

        while(i<=j)
        {
            int mid=(i+j)/2;

            if(nums[mid]<target)
            {
                i=mid+1;
                
                
            }
            else if(nums[mid]>=target)
            {
                j=mid-1;
                if(nums[mid]==target)
                {
                    idx=mid;
                }
            }
            
        }
        return idx;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int f=firstSearch(nums,target);
        int l=lastSearch(nums,target);

        return {f,l};
    }
};